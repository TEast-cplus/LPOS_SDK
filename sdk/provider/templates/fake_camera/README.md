# Fake Camera Provider 模板

用于在无真实摄像头时验证 HAL / SDK 兼容性流程。

## 预期能力

- 循环读取本地视频或生成测试帧
- 模拟断开、超时、格式错误、帧率抖动

## 下一步

1. 按 `provider_spi.h` 导出 C ABI 入口
2. 实现 Unified HAL Camera 契约（由 Edge OS / HAL 规范定义）
3. 通过 HAL Conformance Test

本目录仅为 Provider SDK 模板占位，不含真实实现。
