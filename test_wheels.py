#!/usr/bin/env python3
"""
测试构建的 wheels 是否可以正常工作
"""

import os
import sys
import subprocess
import tempfile
from pathlib import Path


def test_wheel(wheel_path):
    """测试单个 wheel 文件"""
    print(f"\n📦 Testing wheel: {wheel_path.name}")

    # 创建临时虚拟环境
    with tempfile.TemporaryDirectory() as temp_dir:
        venv_path = Path(temp_dir) / "test_env"

        # 创建虚拟环境
        result = subprocess.run([
            sys.executable, "-m", "venv", str(venv_path)
        ], capture_output=True, text=True)

        if result.returncode != 0:
            print(f"❌ Failed to create virtual environment: {result.stderr}")
            return False

        # 确定 Python 可执行文件路径
        if sys.platform == "win32":
            python_exe = venv_path / "Scripts" / "python.exe"
            pip_exe = venv_path / "Scripts" / "pip.exe"
        else:
            python_exe = venv_path / "bin" / "python"
            pip_exe = venv_path / "bin" / "pip"

        # 安装 wheel
        result = subprocess.run([
            str(pip_exe), "install", str(wheel_path)
        ], capture_output=True, text=True)

        if result.returncode != 0:
            print(f"❌ Failed to install wheel: {result.stderr}")
            return False

        # 测试导入
        test_code = """
import xcgui
print(f"✅ xcgui imported successfully")
print(f"Python version: {sys.version}")
print(f"xcgui module: {xcgui}")
"""

        result = subprocess.run([
            str(python_exe), "-c", f"import sys; {test_code}"
        ], capture_output=True, text=True)

        if result.returncode != 0:
            print(f"❌ Failed to import xcgui: {result.stderr}")
            return False

        print(result.stdout.strip())
        return True


def main():
    """主函数"""
    print("🧪 Testing xcgui wheels")
    print("=" * 50)

    # 查找 wheelhouse 目录
    wheelhouse = Path("wheelhouse")
    if not wheelhouse.exists():
        print("❌ wheelhouse directory not found!")
        print("Please run build_wheels.bat or build_wheels.ps1 first")
        return 1

    # 查找所有 wheel 文件
    wheels = list(wheelhouse.glob("*.whl"))
    if not wheels:
        print("❌ No wheel files found in wheelhouse/")
        return 1

    print(f"Found {len(wheels)} wheel(s) to test:")
    for wheel in wheels:
        print(f"  📦 {wheel.name}")

    # 测试每个 wheel
    success_count = 0
    for wheel in wheels:
        try:
            if test_wheel(wheel):
                success_count += 1
            else:
                print(f"❌ Test failed for {wheel.name}")
        except Exception as e:
            print(f"❌ Error testing {wheel.name}: {e}")

    # 总结
    print("\n" + "=" * 50)
    print(f"📊 Test Results: {success_count}/{len(wheels)} wheels passed")

    if success_count == len(wheels):
        print("🎉 All wheels are working correctly!")
        return 0
    else:
        print("⚠️  Some wheels failed testing")
        return 1


if __name__ == "__main__":
    sys.exit(main())