# HTWOS SDK 架构概览

```
Application / ROS2 Adapter / Python
            |
            v
     HTWOS Native SDK  (本仓库)
      |        |        |
   Native   EventBus   ShmChannel
   API      (async)    (data plane)
      |        |        |
      +---- UDS Client -+
            |
            v
     Edge OS Runtime (LPOS / htwosd)
      Atlas / Soma / Provider
```

版本对象：

| 对象 | 当前 |
|------|------|
| HTWOS SDK | 1.0.0 |
| HAL API | 1.0 |
| Provider SPI | 1.0 |
