# NetChat 2.0

#### 介绍
本项目是一个简单的即时通讯程序。

#### 2.0的改动
1. 用C++重新实现了NetChat的所有业务逻辑
2. 将前后端完全剥离。

#### 软件架构
本项目分为三个部分：
1. 前端与静态资源服务器
2. 数据库服务器
3. 即时通讯服务器

#### 目录结构
- 0ENV 运行所需的环境
- 0demo 该项目涉及的某些技术的代码样例，方便快速学习相关技术的使用
- APIServer 与数据库交互的服务端程序
- StaticServer 前端与静态资源服务器
- WebSocketServer 即时通讯服务器

#### 安装教程
>该项目代码可跨平台，但目前仅提供Linux下的环境配置说明

##### Linux配置教程
```
./LinuxInstall.sh

```
#### 参与贡献




