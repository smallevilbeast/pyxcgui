@echo off
REM 使用 uv 和 cibuildwheel 构建多版本 wheels
echo ===============================================
echo Building wheels for xcgui using cibuildwheel
echo ===============================================

REM 检查是否安装了 uv
where uv >nul 2>nul
if %ERRORLEVEL% neq 0 (
    echo Error: uv is not installed or not in PATH
    echo Please install uv first: https://docs.astral.sh/uv/
    exit /b 1
)

echo Setting up Python environment...
REM 确保有 Python 3.11
uv python install 3.11

echo Installing build dependencies...
REM 安装 cibuildwheel 到系统环境
uv pip install --system cibuildwheel

echo Starting wheel build process...
echo This may take 10-20 minutes depending on your system...
echo cibuildwheel will automatically detect Visual Studio...

REM 设置环境变量以避免警告
set Py_DEBUG=0

REM 构建 wheels - 让 cibuildwheel 自动检测编译器
cibuildwheel --output-dir wheelhouse

if %ERRORLEVEL% equ 0 (
    echo.
    echo ===============================================
    echo Build completed successfully!
    echo Wheels are available in: wheelhouse\
    echo.
    echo Available wheels:
    dir /b wheelhouse\*.whl
    echo ===============================================
) else (
    echo.
    echo ===============================================
    echo Build failed with error code %ERRORLEVEL%
    echo Check the output above for details
    echo ===============================================
    exit /b %ERRORLEVEL%
)

echo.
echo To test a wheel, run:
echo   uv pip install wheelhouse\[wheel_name].whl
echo   python -c "import xcgui; print('Success!')"
echo.
echo To upload to PyPI, run:
echo   uv pip install twine
echo   uv run twine upload wheelhouse\*.whl