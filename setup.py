from setuptools import setup, find_packages
from pybind11.setup_helpers import Pybind11Extension
from distutils.errors import *
from distutils import log
from distutils.command.build_ext import build_ext
import distutils.util
from distutils._msvccompiler import MSVCCompiler
import os

from codecs import open
import os
import sys
import platform
import re
import glob
import pathlib
from distutils.ccompiler import CCompiler
from multiprocessing.pool import ThreadPool as Pool


from pybind11.setup_helpers import ParallelCompile

# 并行编译
ParallelCompile("NPY_NUM_BUILD_JOBS", needs_recompile=True).install()

# Patch MSVCCompiler to remove /MD flag on Windows
if platform.system() == 'Windows':
    original_initialize = MSVCCompiler.initialize

    def patched_initialize(self, plat_name=None):
        original_initialize(self, plat_name)
        # Remove /MD and /MDd from compile_options if they exist
        if hasattr(self, 'compile_options'):
            self.compile_options = [opt for opt in self.compile_options if opt not in ['/MD', '/MDd']]
        # Also remove from compile_options_debug if it exists
        if hasattr(self, 'compile_options_debug'):
            self.compile_options_debug = [opt for opt in self.compile_options_debug if opt not in ['/MD', '/MDd']]

    MSVCCompiler.initialize = patched_initialize


def compile(self, sources, output_dir=None, macros=None, include_dirs=None, debug=0, extra_preargs=None,
            extra_postargs=None, depends=None):
    macros, objects, extra_postargs, pp_opts, build = self._setup_compile(output_dir, macros, include_dirs, sources,
                                                                          depends, extra_postargs)
    cc_args = self._get_cc_args(pp_opts, debug, extra_preargs)

    def f(x):
        try:
            src, ext = build[x]
        except KeyError:
            return

        self._compile(x, src, ext, cc_args, extra_postargs, pp_opts)

    pool = Pool(processes=6)
    pool.map(f, objects)

    return objects


# Overwrite to enable multiprocess compilation
CCompiler.compile = compile

target_os = 'none'
if sys.platform == 'darwin':
    target_os = 'darwin'
elif os.name == 'posix':
    target_os = 'posix'
elif platform.system() == 'Windows':
    target_os = 'win32'

target_os_arch = 'x64' if sys.maxsize > 2**32 else 'x86'


def filter_sources(sources):
    """Filters sources into c, cpp and objc"""
    cpp_ext_match = re.compile(r'.*[.](cpp|cxx|cc|hpp)\Z', re.I).match
    c_ext_match = re.compile(r'.*[.](c|C)\Z', re.I).match
    objc_ext_match = re.compile(r'.*[.]m\Z', re.I).match

    c_sources = []
    cpp_sources = []
    objc_sources = []
    other_sources = []
    for source in sources:
        if c_ext_match(source):
            c_sources.append(source)
        elif cpp_ext_match(source):
            cpp_sources.append(source)
        elif objc_ext_match(source):
            objc_sources.append(source)
        else:
            other_sources.append(source)
    return c_sources, cpp_sources, objc_sources, other_sources


def build_extension(self, ext):
    """Modified version of build_extension method from distutils.
       Can handle compiler args for different files"""

    sources = ext.sources
    if sources is None or not isinstance(sources, (list, tuple)):
        raise DistutilsSetupError(
            "in 'ext_modules' option (extension '%s'), "
            "'sources' must be present and must be "
            "a list of source filenames" % ext.name)

    sources = list(sources)
    ext_path = self.get_ext_fullpath(ext.name)
    depends = sources + ext.depends
    # Check if extension needs rebuilding
    needs_rebuild = self.force
    if not needs_rebuild and os.path.exists(ext_path):
        ext_mtime = os.path.getmtime(ext_path)
        for dep in depends:
            if os.path.exists(dep) and os.path.getmtime(dep) > ext_mtime:
                needs_rebuild = True
                break
    elif not os.path.exists(ext_path):
        needs_rebuild = True

    if not needs_rebuild:
        log.debug("skipping '%s' extension (up-to-date)", ext.name)
        return
    else:
        log.info("building '%s' extension", ext.name)

    sources = self.swig_sources(sources, ext)

    extra_args = ext.extra_compile_args or []
    extra_c_args = getattr(ext, "extra_compile_c_args", [])
    extra_cpp_args = getattr(ext, "extra_compile_cpp_args", [])
    extra_objc_args = getattr(ext, "extra_compile_objc_args", [])
    macros = ext.define_macros[:]
    for undef in ext.undef_macros:
        macros.append((undef,))

    c_sources, cpp_sources, objc_sources, other_sources = filter_sources(sources)

    def _compile(src, args):
        return self.compiler.compile(src,
                                     output_dir=self.build_temp,
                                     macros=macros,
                                     include_dirs=ext.include_dirs,
                                     debug=self.debug,
                                     extra_postargs=extra_args + args,
                                     depends=ext.depends)

    objects = []
    objects += _compile(c_sources, extra_c_args)
    objects += _compile(cpp_sources, extra_cpp_args)
    objects += _compile(objc_sources, extra_objc_args)
    objects += _compile(other_sources, [])

    self._built_objects = objects[:]
    if ext.extra_objects:
        objects.extend(ext.extra_objects)

    extra_args = ext.extra_link_args or []

    language = ext.language or self.compiler.detect_language(sources)
    self.compiler.link_shared_object(
        objects, ext_path,
        libraries=self.get_libraries(ext),
        library_dirs=ext.library_dirs,
        runtime_library_dirs=ext.runtime_library_dirs,
        extra_postargs=extra_args,
        export_symbols=self.get_export_symbols(ext),
        debug=self.debug,
        build_temp=self.build_temp,
        target_lang=language)


# patching
build_ext.build_extension = build_extension


class CustomBuildExt(build_ext):
    """Custom build_ext to handle runtime library flags properly on Windows"""
    pass

definitions = {
    'win32': [("GLFW_USE_HYBRID_HPG", 0)],
}

libs = {
    'win32': ["kernel32", "user32", "gdi32", "winspool",
              "comdlg32", "advapi32", "shell32", "ole32",
              "oleaut32", "uuid", "odbc32", "odbccp32"],
}

extra_libs = {
    'win32': ["XCGUI.lib"]
}

extra_libs_dir = {
    'win32': [f"Lib/{target_os_arch}"]
}

extra_link = {
    'win32': [],
}

extra_compile_args = {
    'darwin': [],
    'posix': [],
    'win32': ["/MT", "/EHsc", "/bigobj", "/utf-8", "/wd4267"],
}

extra_compile_cpp_args = {
    'darwin': ['-std=c++11'],
    'posix': ['-std=c++11'],
    'win32': [],
}

xcgui_sources = [str(path) for path in pathlib.Path("pyxcgui").rglob("*.cpp")]


def add_prefix(l, prefix):
    return [os.path.join(prefix, x) for x in l]


extension = Pybind11Extension("xcgui._xcgui",
                            xcgui_sources,
                            define_macros=definitions[target_os],
                            include_dirs=[
                                "pyxcgui",
                                "."
                            ],
                            extra_compile_args=extra_compile_args[target_os],
                            extra_link_args=extra_link[target_os],
                            libraries=libs[target_os],
                            extra_objects=extra_libs[target_os],
                            library_dirs=extra_libs_dir[target_os])

extension.extra_compile_cpp_args = extra_compile_cpp_args[target_os]

setup(
    cmdclass={'build_ext': CustomBuildExt},
    ext_modules=[extension]
)
