[简体中文](README.md) | [繁體中文](README.zh-TW.md) | [English](README.en.md) | [Visual website](https://masterai-top.github.io/Texas-Holdem-Offline-Poker-Event-System/en/)

# Texas Holdem Offline Poker Event Management Source Code

A Texas Holdem event system centered on online qualifiers, live-event registration, tournament ticket exchange and the transition to an offline competition. The repository contains C++ lobby and match-room code, Tars interfaces, Protobuf/MySQL configuration, Unity assets and authentic product screenshots.

> This repository presents source and interface material, not a guaranteed turnkey deployment. Verify the delivered modules, dependencies, licensing and local compliance requirements before use.

## Product position

Rather than presenting a generic poker table, this project documents a player journey from online qualification to a live poker event: discover an event, review registration details, exchange an eligible tournament benefit, and enter the match-room workflow.

## Product capabilities

- **Event discovery:** home and online-event interfaces expose tournament and qualifier entry points.
- **Registration journey:** a dedicated screen presents event details and registration status.
- **Ticket and benefit exchange:** list and detail interfaces connect online qualification with live-event eligibility.
- **Match-room management:** source interfaces cover room creation, updates, queries and member changes.
- **Lobby and player services:** user profile, account, item and lobby request structures are included.
- **Table support screens:** repository screenshots include an odds calculator and analytics interface; availability must be verified against the delivered build.

## Event workflow

1. Sign in and open the event home.
2. Browse online qualifiers or a target live event.
3. Review tournament conditions, time and registration details.
4. Register or exchange the relevant entry benefit.
5. Maintain tournament rooms and participants through the server interfaces.
6. Connect to on-site check-in, seating and schedule operations after verifying the corresponding delivered modules.

## Product screenshots

| Event home | Online qualifiers | Event registration |
| --- | --- | --- |
| ![Offline poker event home](Screenshots/0首页%20-%20副本.jpg) | ![Online poker qualifier list](Screenshots/0线上赛事.jpg) | ![Live poker event registration](Screenshots/报名.jpg) |

| Ticket exchange | Exchange detail | Odds calculator |
| --- | --- | --- |
| ![Tournament ticket exchange](Screenshots/兑换01.jpg) | ![Live-event exchange detail](Screenshots/兑换02.jpg) | ![Poker odds calculator](Screenshots/胜率计算器1.jpg) |

## Technical structure

| Layer | Evidence available in the repository |
| --- | --- |
| Server | C++ lobby service, user processing, match-room operations and game hooks |
| RPC/contracts | Tars services and `.tars` protocol definitions |
| Data | Protobuf references, MySQL client and data-proxy interfaces |
| Client assets | Unity AssetBundles and manifest files |
| Build | Linux Makefile with environment-specific external paths |

## Code map and build note

`HallServer.*` boots the lobby service. `RoomProcessor.*` and `RoomProto.tars` define match-room and participant operations. `UserInfoProcessor.*` handles player data. This is not a Node.js project: the previous npm quick-start was incorrect. Building requires compatible Tars, Protobuf, MySQL and common protocol/modules referenced by the Makefile but not bundled here.

## Contact and due diligence

Telegram: [@xuzongbin001](https://t.me/xuzongbin001) · Email: masterai918@gmail.com

Review the demo, source scope, dependencies, intellectual-property status and applicable laws before use. No deployment, revenue or search-ranking outcome is guaranteed.

