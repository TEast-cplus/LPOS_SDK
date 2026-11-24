# HTWOS SDK 工程骨架设计

> 日期：2026-11-24  
> 仓库：`LPOS_SDK`（独立 Git）  
> 版本目标：SDK 1.0.0  
> 状态：已确认，首期落地框架

## 1. 决策摘要

| 项 | 选择 |
|----|------|
| 产品定位 | 纯开发者 SDK（不含 Edge OS 运行时） |
| 对接方式 | 客户端库 + IPC（UDS / Event / SHM） |
| 首期深度 | 五件套目录全开 + Native 可编译最小骨架 |
| 语言 | C++20（Native）；Python/ROS2 仅模板 |
| 命名空间 | `Hantewin::Htwos` |
| 编码规范 | `.cursor/rules/hantewin-cpp-*.mdc` |

## 2. 边界

**SDK 负责**：公开 API、IPC 客户端、Capability 查询、Provider/ROS2/Tools 模板、示例、打包骨架、平台/能力描述。

**SDK 不负责**：`htwosd`、Atlas/Soma、真实 Provider、Yocto 镜像、OTA、Cloud。

**与 Edge OS**：运行时服务在 `LPOS`；本仓库不 vendoring 厂商 SDK；HAL 设备类契约由 HAL 规范定义，SDK 暴露应用侧 `DeviceSession` / Capability / IPC 客户端。

## 3. 仓库布局（方案 1）

```
LPOS_SDK/
├── CMakeLists.txt
├── VERSION
├── cmake/
├── sdk/
│   ├── common/          # 错误码、版本、基础类型
│   ├── native/          # C/C++ 客户端库（首期可编译）
│   ├── python/          # 绑定模板
│   ├── provider/        # Provider SDK 模板 + SPI 头骨架
│   └── ros2/            # ROS2 Adapter 模板
├── platform/            # 平台资料（capability matrix 输入）
├── capabilities/        # 能力描述 schema + 示例 profile
├── tools/               # Device Explorer 等工具占位
├── examples/native/
├── tests/unit/
├── packaging/
├── scripts/
└── docs/
```

## 4. Native 模块职责

| 模块 | 职责 |
|------|------|
| `common` | `Status`、版本宏、公共类型 |
| `native` | `SdkClient`、能力查询、IPC 客户端占位 |
| `ipc` | UDS 命令通道、Event Bus、Shared Memory（首期 stub） |
| `provider` | 版本化 C ABI SPI 头与模板（厂商实现用） |

## 5. 通信分工（对齐总体构建）

| 机制 | 用途 | 首期 |
|------|------|------|
| Native API | 进程内同步调用 | 客户端外壳 |
| Event Bus | 异步状态/故障 | 接口占位 |
| Unix Domain Socket | 跨进程命令/配置/查询 | stub 连接 |
| Shared Memory | 图像/点云/音视频 | 接口占位 |
| DDS/ROS2/MQTT | 分布式 | ros2 模板目录 |

## 6. 版本对象

- HTWOS SDK：1.0.0  
- HAL API / Provider SPI：对外声明为 1.0（头文件宏，真源仍以 Edge/HAL 规范为准）  
- 平台描述：随 `platform.yaml` 独立修订

## 7. 非目标（首期）

- 真实 IPC 协议编解码与联调  
- Python 扩展编译  
- ROS2 包构建  
- Device Explorer GUI  
- 完整 Fake Runtime

## 8. 验收

1. 干净克隆后 `cmake -S . -B build && cmake --build build` 可通过（有 C++20 编译器时）。  
2. `examples/native/hello_capability` 可链接并打印 SDK 版本与 stub 能力。  
3. 五件套目录与 README 齐全；仓库与 `LPOS` 无强制 submodule 依赖。
