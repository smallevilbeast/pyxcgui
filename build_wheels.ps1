# PowerShell 版本的 wheel 构建脚本
# 使用 uv 和 cibuildwheel 构建多版本 wheels

Write-Host "===============================================" -ForegroundColor Green
Write-Host "Building wheels for xcgui using cibuildwheel" -ForegroundColor Green
Write-Host "===============================================" -ForegroundColor Green

# 检查是否安装了 uv
if (!(Get-Command uv -ErrorAction SilentlyContinue)) {
    Write-Host "Error: uv is not installed or not in PATH" -ForegroundColor Red
    Write-Host "Please install uv first: https://docs.astral.sh/uv/" -ForegroundColor Yellow
    exit 1
}

Write-Host "Setting up Python environment..." -ForegroundColor Blue

# 确保有 Python 3.11
try {
    # uv python install 3.11
    Write-Host "Python 3.11 ready" -ForegroundColor Green
} catch {
    Write-Host "Failed to install Python 3.11: $_" -ForegroundColor Red
    exit 1
}

Write-Host "Installing build dependencies..." -ForegroundColor Blue

# 安装 cibuildwheel 到系统环境
try {
    uv pip install --system cibuildwheel
    Write-Host "cibuildwheel installed successfully" -ForegroundColor Green
} catch {
    Write-Host "Failed to install cibuildwheel: $_" -ForegroundColor Red
    exit 1
}

Write-Host "Starting wheel build process..." -ForegroundColor Blue
Write-Host "This may take 10-20 minutes depending on your system..." -ForegroundColor Yellow
Write-Host "cibuildwheel will automatically detect Visual Studio..." -ForegroundColor Cyan

# 构建 wheels - 让 cibuildwheel 自动检测编译器
try {
    $env:CIBW_BUILD_VERBOSITY = "1"
    $env:Py_DEBUG = "0"  # 避免 ABI 警告
    cibuildwheel --output-dir wheelhouse

    Write-Host ""
    Write-Host "===============================================" -ForegroundColor Green
    Write-Host "Build completed successfully!" -ForegroundColor Green
    Write-Host "Wheels are available in: wheelhouse\" -ForegroundColor Green
    Write-Host ""
    Write-Host "Available wheels:" -ForegroundColor Cyan
    Get-ChildItem -Path "wheelhouse\*.whl" | ForEach-Object { Write-Host "  $($_.Name)" -ForegroundColor White }
    Write-Host "===============================================" -ForegroundColor Green
} catch {
    Write-Host ""
    Write-Host "===============================================" -ForegroundColor Red
    Write-Host "Build failed: $_" -ForegroundColor Red
    Write-Host "Check the output above for details" -ForegroundColor Red
    Write-Host "===============================================" -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "To test a wheel, run:" -ForegroundColor Yellow
Write-Host "  uv pip install wheelhouse\[wheel_name].whl" -ForegroundColor White
Write-Host "  python -c `"import xcgui; print('Success!')`"" -ForegroundColor White
Write-Host ""
Write-Host "To upload to PyPI, run:" -ForegroundColor Yellow
Write-Host "  uv pip install twine" -ForegroundColor White
Write-Host "  uv run twine upload wheelhouse\*.whl" -ForegroundColor White