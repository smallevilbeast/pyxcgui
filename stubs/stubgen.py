module_name = "_xcgui"
exec("from xcgui import %s" % module_name)

from pybind11_stubgen import ModuleStubsGenerator

module = ModuleStubsGenerator(module_name)
module.parse()
module.write_setup_py = False


with open("..\\xcgui\\%s.pyi" % module_name, "w") as fp:
    fp.write("#\n# Automatically generated file, do not edit!\n#\n\n")
    lines = module.to_lines()
    fp.write("\n".join(lines))

if __name__ == '__main__':
    pass
