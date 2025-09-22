#!/usr/bin/env python3
"""
发布 wheels 到 PyPI
支持 TestPyPI 和正式 PyPI
"""

import os
import sys
import subprocess
import argparse
from pathlib import Path


def check_twine():
    """检查 twine 是否安装"""
    try:
        subprocess.run(["twine", "--version"], check=True, capture_output=True)
        return True
    except (subprocess.CalledProcessError, FileNotFoundError):
        return False


def install_twine():
    """安装 twine"""
    print("📦 Installing twine...")
    result = subprocess.run(["uv", "pip", "install", "--system", "twine"],
                          capture_output=True, text=True)
    if result.returncode != 0:
        print(f"❌ Failed to install twine: {result.stderr}")
        return False
    print("✅ twine installed successfully")
    return True


def check_wheels():
    """检查 wheel 文件"""
    wheelhouse = Path("wheelhouse")
    if not wheelhouse.exists():
        print("❌ wheelhouse directory not found!")
        print("Please run build_wheels.bat first")
        return []

    wheels = list(wheelhouse.glob("*.whl"))
    sdists = list(Path("dist").glob("*.tar.gz")) if Path("dist").exists() else []

    all_files = wheels + sdists

    if not all_files:
        print("❌ No wheel or sdist files found!")
        return []

    print(f"📦 Found {len(all_files)} package(s) to upload:")
    for file in all_files:
        print(f"  📄 {file}")

    return all_files


def check_files(files):
    """使用 twine check 检查文件"""
    print("\n🔍 Checking package files...")

    file_paths = [str(f) for f in files]
    result = subprocess.run(["twine", "check"] + file_paths,
                          capture_output=True, text=True)

    if result.returncode != 0:
        print(f"❌ Package check failed: {result.stderr}")
        print(result.stdout)
        return False

    print("✅ All packages passed checks")
    return True


def upload_to_pypi(files, test=False):
    """上传到 PyPI"""
    repository = "testpypi" if test else "pypi"
    repository_name = "TestPyPI" if test else "PyPI"

    print(f"\n📤 Uploading to {repository_name}...")

    file_paths = [str(f) for f in files]
    cmd = ["twine", "upload"]

    if test:
        cmd.extend(["--repository", "testpypi"])

    cmd.extend(file_paths)

    print(f"Running: {' '.join(cmd)}")

    result = subprocess.run(cmd, text=True)

    if result.returncode == 0:
        print(f"🎉 Successfully uploaded to {repository_name}!")
        if test:
            print("\n📝 To install from TestPyPI:")
            print("  pip install --index-url https://test.pypi.org/simple/ xcgui")
        else:
            print("\n📝 To install from PyPI:")
            print("  pip install xcgui")
        return True
    else:
        print(f"❌ Upload to {repository_name} failed")
        return False


def main():
    """主函数"""
    parser = argparse.ArgumentParser(description="Publish xcgui wheels to PyPI")
    parser.add_argument("--test", action="store_true",
                       help="Upload to TestPyPI instead of PyPI")
    parser.add_argument("--check-only", action="store_true",
                       help="Only check files, don't upload")

    args = parser.parse_args()

    print("🚀 xcgui Wheel Publisher")
    print("=" * 40)

    # 检查 twine
    if not check_twine():
        if not install_twine():
            return 1

    # 检查文件
    files = check_wheels()
    if not files:
        return 1

    # 检查文件质量
    if not check_files(files):
        return 1

    if args.check_only:
        print("✅ All checks passed. Files are ready for upload.")
        return 0

    # 确认上传
    repository_name = "TestPyPI" if args.test else "PyPI"
    response = input(f"\n❓ Upload {len(files)} package(s) to {repository_name}? [y/N]: ")

    if response.lower() not in ('y', 'yes'):
        print("❌ Upload cancelled by user")
        return 0

    # 上传
    if upload_to_pypi(files, test=args.test):
        return 0
    else:
        return 1


if __name__ == "__main__":
    sys.exit(main())