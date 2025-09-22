# xcgui 构建指南

本项目使用 `uv` 和 `cibuildwheel` 来构建支持多个 Python 版本的 wheels。

## 前置要求

1. **安装 uv**
   ```bash
   # Windows (PowerShell)
   powershell -c "irm https://astral.sh/uv/install.ps1 | iex"

   # 或者使用 pip
   pip install uv
   ```

2. **Visual Studio Build Tools** (Windows)
   - 安装 Visual Studio 2019/2022 或 Build Tools
   - 确保包含 C++ 构建工具

3. **安装开发依赖**
   ```bash
   uv pip install -e .[dev]
   ```

## 快速开始

### 本地构建所有 wheels

```bash
# 方法 1: 使用批处理脚本 (推荐)
.\build_wheels.bat

# 方法 2: 使用 PowerShell 脚本
.\build_wheels.ps1

# 方法 3: 手动运行
uv pip install --system cibuildwheel
cibuildwheel --output-dir wheelhouse
```

### 测试构建的 wheels

```bash
# 测试所有构建的 wheels
python test_wheels.py
```

### 发布到 PyPI

```bash
# 发布到 TestPyPI (测试)
python publish_wheels.py --test

# 发布到正式 PyPI
python publish_wheels.py

# 只检查文件，不上传
python publish_wheels.py --check-only
```

## 详细说明

### 支持的 Python 版本

本项目支持以下 Python 版本的 Windows x64 wheels：
- Python 3.9
- Python 3.10
- Python 3.11
- Python 3.12
- Python 3.13

### 构建配置

构建配置在 `pyproject.toml` 中的 `[tool.cibuildwheel]` 部分：

```toml
[tool.cibuildwheel]
build = ["cp39-win_amd64", "cp310-win_amd64", "cp311-win_amd64", "cp312-win_amd64", "cp313-win_amd64"]
skip = ["*-win32", "*-manylinux_i686", "*-musllinux_*", "pp*"]
test-command = "python -c \"import xcgui; print('xcgui import successful')\""
```


### 手动步骤

如果需要手动控制构建过程：

```bash
# 1. 设置环境
uv python pin 3.11
uv venv
uv pip install -e .[dev]

# 2. 构建特定 Python 版本
uv python install 3.9
cibuildwheel --only cp39-win_amd64

# 3. 构建所有版本
cibuildwheel

# 4. 检查构建结果
dir wheelhouse
python test_wheels.py

# 5. 上传到 PyPI
python publish_wheels.py
```

## 故障排除

### 常见问题

1. **找不到 MSVC 编译器**
   ```
   error: Microsoft Visual C++ 14.0 is required
   ```
   - 安装 Visual Studio Build Tools
   - 或使用 Visual Studio Community

2. **pybind11 安装失败**
   ```bash
   uv pip install pybind11>=2.10.0
   ```

3. **权限问题**
   - 使用管理员权限运行 PowerShell/Command Prompt

4. **构建时间过长**
   - 正常情况下每个版本需要 2-5 分钟
   - 总共 5 个版本约需 10-20 分钟

### 调试构建

启用详细输出：
```bash
$env:CIBW_BUILD_VERBOSITY = "3"
cibuildwheel --output-dir wheelhouse
```

### 清理构建缓存

```bash
# 清理 uv 缓存
uv cache clean

# 清理构建目录
Remove-Item -Recurse -Force build, dist, wheelhouse, *.egg-info
```

## 发布流程

### 准备发布

1. 更新版本号 (`pyproject.toml`)
2. 更新 CHANGELOG
3. 提交所有更改

### 发布到 PyPI

```bash
# 1. 更新版本号并提交
# 编辑 pyproject.toml 中的 version = "0.1.9"

# 2. 构建 wheels
.\build_wheels.bat

# 3. 测试构建结果
python test_wheels.py

# 4. 发布到 PyPI
python publish_wheels.py

# 5. 创建 git 标签（可选）
git tag v0.1.9
git push origin v0.1.9
```

## 性能优化

- 使用 `uv` 进行快速包管理
- 启用构建缓存
- 并行构建多个版本
- 本地多线程构建

## 更多信息

- [uv 文档](https://docs.astral.sh/uv/)
- [cibuildwheel 文档](https://cibuildwheel.readthedocs.io/)
- [pybind11 文档](https://pybind11.readthedocs.io/)