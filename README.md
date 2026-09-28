[简体中文](README.md) | [繁體中文](README.zh-TW.md) | [English](README.en.md) | [图文网站](https://masterai-top.github.io/Texas-Holdem-Offline-Poker-Event-System/)

**赛事专题：** [线上资格赛](https://masterai-top.github.io/Texas-Holdem-Offline-Poker-Event-System/online-qualifier/) · [线下赛事报名](https://masterai-top.github.io/Texas-Holdem-Offline-Poker-Event-System/live-event-registration/) · [赛事门票与权益](https://masterai-top.github.io/Texas-Holdem-Offline-Poker-Event-System/tournament-ticket/) · [C++/Tars 比赛房间](https://masterai-top.github.io/Texas-Holdem-Offline-Poker-Event-System/match-room-server/)

# 德州扑克线下赛事管理系统源码

面向线上资格赛、线下比赛报名、赛事门票与现场比赛衔接的德州扑克赛事系统。仓库包含 C++ 大厅与房间相关代码、Tars 接口、Protobuf/MySQL 依赖配置、Unity 资源和真实产品界面，适合用于研究德州赛事管理、比赛房间与玩家流程。

> 本仓库展示的是项目代码与产品界面资料，不代表开箱即用的完整部署包。实际功能、依赖、授权及合规要求请以代码、交付清单和目标地区规定为准。

## 产品定位

它不是只介绍牌桌规则的普通德州项目，而是围绕“线上获取参赛资格，再衔接线下赛事”的流程组织产品入口：用户可查看线上赛事、进入报名页、了解兑换项目，并通过大厅与比赛房间相关模块参与赛事流程。

| 场景 | 产品入口 | 仓库依据 |
| --- | --- | --- |
| 线上资格赛 | 线上赛事列表与赛事入口 | `Screenshots/0线上赛事.jpg` |
| 线下赛事报名 | 报名页、项目说明与状态 | `Screenshots/报名.jpg` |
| 资格/权益兑换 | 兑换列表和详情界面 | `Screenshots/兑换01.jpg`、`兑换02.jpg` |
| 比赛房间 | 创建、更新、查询比赛房间与成员 | `RoomProcessor.*`、`RoomProto.tars` |
| 玩家与大厅 | 玩家资料、账户、道具和大厅请求 | `UserInfoProcessor.*`、`HallServantImp.h` |

## 核心功能

- **赛事入口与发现**：首页和线上赛事界面呈现活动入口、赛事信息与报名路径。
- **比赛报名流程**：从赛事选择进入报名详情，适合串联资格审核、参赛状态与线下活动信息。
- **门票/权益兑换展示**：兑换列表与详情页用于承接线上资格和线下参赛权益。
- **比赛房间管理**：源码提供比赛房间创建、更新、列表查询、成员更新与删除等接口。
- **大厅与用户服务**：包含用户资料、账户、地址、道具、备注以及大厅请求处理的服务端结构。
- **牌桌辅助界面**：仓库截图展示胜率计算器和数据界面；是否启用及具体规则应按实际版本核验。

## 赛事流程

1. 玩家登录并进入赛事首页。
2. 浏览线上赛事或目标线下活动的资格入口。
3. 查看比赛条件、时间和报名信息。
4. 完成报名或兑换对应参赛权益。
5. 系统通过比赛房间与成员接口维护参赛状态。
6. 线下执行签到、座位、赛程和结果流程时，应与实际运营后台及交付模块核对。

## 产品截图

| 赛事首页 | 线上赛事 | 报名页面 |
| --- | --- | --- |
| ![德州扑克线下赛事系统首页](Screenshots/0首页%20-%20副本.jpg) | ![德州扑克线上资格赛列表](Screenshots/0线上赛事.jpg) | ![德州扑克线下比赛报名](Screenshots/报名.jpg) |

| 权益兑换 | 兑换详情 | 胜率计算器 |
| --- | --- | --- |
| ![赛事门票与权益兑换](Screenshots/兑换01.jpg) | ![线下赛事兑换详情](Screenshots/兑换02.jpg) | ![德州牌桌胜率计算器](Screenshots/胜率计算器1.jpg) |

## 技术结构

| 层级 | 仓库中可确认的技术/模块 |
| --- | --- |
| 服务端 | C++，大厅服务、用户处理、比赛房间处理与游戏逻辑接口 |
| RPC/接口 | Tars 服务与 `.tars` 协议文件 |
| 数据序列化 | Protobuf 依赖及生成头文件引用 |
| 数据访问 | MySQL 客户端及 Tars 数据代理接口 |
| 客户端资源 | Unity AssetBundle 与 manifest 文件 |
| 构建 | Linux Makefile；依赖路径与内部公共模块需按部署环境调整 |

## 代码导读

- `HallServer.*`：大厅服务启动与配置加载。
- `HallServantImp.h`：用户、账户、比赛房间等大厅接口。
- `RoomProcessor.*`：比赛房间和参赛成员的数据操作。
- `RoomProto.tars`：比赛房间、成员及请求/响应结构。
- `UserInfoProcessor.*`：用户资料和相关业务处理。
- `game*.cpp`、`sitdown.cpp`：牌桌开始、参数、入座等游戏逻辑入口。
- `Screenshots/`：本 README 和 Pages 使用的真实产品截图。

## 构建说明

仓库不是 Node.js 项目，请勿使用旧文档中的 `npm install`。现有 `makefile` 引用了 Tars、Protobuf、MySQL 以及未随仓库公开的公共协议/模块路径，因此在编译前需要准备匹配依赖，并根据环境修正 include、library 和 `HallServer.mk` 路径。建议先完成代码与依赖审计，再在隔离测试环境构建。

## 适用关键词与边界

本页聚焦：**德州扑克线下赛事系统、德州赛事管理源码、线上资格赛、线下比赛报名、赛事门票、offline poker tournament、live poker event management**。为避免与通用德州俱乐部、普通 MTT 引擎项目互相竞争，本仓库不把“万能德州源码”作为唯一定位。

## 联系与核验

- Telegram：[@xuzongbin001](https://t.me/xuzongbin001)
- Email：masterai918@gmail.com

如需评估，请先核对演示、源码范围、第三方依赖、构建流程、知识产权和当地法规。仓库内容不构成收益、排名或上线承诺。
