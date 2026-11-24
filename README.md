# HTWOS SDK（LPOS_SDK）

机器人开发工具体系：面向应用与第三方的 **HTWOS SDK 1.0.0**。

本仓库独立于 Edge OS（`LPOS`）：只交付开发包、契约客户端与模板，不包含 `htwosd` / Atlas / Soma / 系统镜像。

## 产品组成

| 组件 | 路径 | 首期状态 |
|------|------|----------|
| Native C/C++ SDK | `sdk/native` | 可编译客户端骨架 + IPC stub |
| Common | `sdk/common` | 版本 / 错误码 |
| Python SDK | `sdk/python` | 包占位 |
| Provider SDK | `sdk/provider` | SPI 头 + Fake Camera 模板 |
| ROS2 Adapter SDK | `sdk/ros2` | ament 包占位 |
| Developer Tools | `tools/device_explorer` | 目录占位 |
| Platform / Capability | `platform/` `capabilities/` | RK3588 示例描述 |

## 快速构建（Linux / 交叉环境）

```bash
./scripts/build.sh
./build/examples/native/hello_capability/htwos_hello_capability
```

Windows（需已安装 CMake + C++20 工具链）：

```powershell
.\scripts\build.ps1
```

## 通信模型

| 通道 | 用途 |
|------|------|
| Native API | 进程内同步调用 |
| Unix Domain Socket | 跨进程命令 / 配置 / 查询 |
| Event Bus | 异步状态 / 故障 / 生命周期 |
| Shared Memory | 图像 / 点云 / 音视频 / Tensor |

首期 IPC 为 stub，可联调真实协议后再替换实现。

## 文档

- 设计说明：`docs/superpowers/specs/2026-11-24-htwos-sdk-design.md`
- 架构概览：`docs/architecture/sdk-overview.md`
- 上游设计真源：`LPOS/doc`（HAL / Core 等）

## 版本

见根目录 `VERSION`（当前 `1.0.0`）。
