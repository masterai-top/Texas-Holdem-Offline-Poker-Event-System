[简体中文](README.md) | [繁體中文](README.zh-TW.md) | [English](README.en.md) | [圖文網站](https://masterai-top.github.io/Texas-Holdem-Offline-Poker-Event-System/zh-tw/)

**賽事專題：** [線上資格賽](https://masterai-top.github.io/Texas-Holdem-Offline-Poker-Event-System/online-qualifier/) · [線下賽事報名](https://masterai-top.github.io/Texas-Holdem-Offline-Poker-Event-System/live-event-registration/) · [賽事門票與權益](https://masterai-top.github.io/Texas-Holdem-Offline-Poker-Event-System/tournament-ticket/) · [C++/Tars 比賽房間](https://masterai-top.github.io/Texas-Holdem-Offline-Poker-Event-System/match-room-server/)

# 德州撲克線下賽事管理系統原始碼

面向線上資格賽、線下比賽報名、賽事門票與現場比賽銜接的德州撲克賽事系統。倉庫包含 C++ 大廳與房間程式碼、Tars 介面、Protobuf/MySQL 相依設定、Unity 資源及真實產品畫面。

> 本倉庫展示專案程式碼與介面資料，不代表開箱即用的完整部署包。實際功能、相依、授權及合規要求應以程式碼、交付清單和目標地區規定為準。

## 產品定位

本專案聚焦「線上取得參賽資格，再銜接線下賽事」：玩家瀏覽線上賽事、查看報名資訊、兌換參賽權益，再由大廳、比賽房間與成員模組承接賽事流程。

## 主要功能

- **賽事入口**：首頁與線上賽事列表呈現活動和資格賽入口。
- **比賽報名**：展示條件、時間、報名資料與狀態。
- **門票/權益兌換**：使用兌換列表和詳情頁承接線上資格與線下參賽權益。
- **比賽房間管理**：支援房間建立、更新、查詢和成員資料操作介面。
- **大廳與玩家服務**：包含玩家資料、帳戶、道具及大廳請求的程式結構。
- **牌桌輔助畫面**：截圖包含勝率計算器與資料頁；可用功能須按交付版本核驗。

## 賽事流程

登入 → 瀏覽線上資格賽 → 查看比賽條件 → 報名或兌換權益 → 維護比賽房間與成員 → 銜接線下簽到、座位與賽程。線下執行模組是否完整包含，須依實際交付清單確認。

## 產品截圖

| 賽事首頁 | 線上賽事 | 比賽報名 |
| --- | --- | --- |
| ![德州撲克線下賽事首頁](Screenshots/0首页%20-%20副本.jpg) | ![線上資格賽列表](Screenshots/0线上赛事.jpg) | ![線下比賽報名](Screenshots/报名.jpg) |

| 權益兌換 | 兌換詳情 | 勝率計算器 |
| --- | --- | --- |
| ![賽事門票兌換](Screenshots/兑换01.jpg) | ![賽事兌換詳情](Screenshots/兑换02.jpg) | ![牌桌勝率計算器](Screenshots/胜率计算器1.jpg) |

## 技術架構

| 層級 | 可由倉庫確認的內容 |
| --- | --- |
| 服務端 | C++ 大廳服務、使用者處理、比賽房間與遊戲邏輯介面 |
| RPC/協議 | Tars 與 `.tars` 定義 |
| 資料 | Protobuf、MySQL 客戶端及資料代理介面 |
| 客戶端資源 | Unity AssetBundle 與 manifest |
| 建置 | Linux Makefile；需補齊並調整外部相依路徑 |

## 程式導讀與建置

`HallServer.*` 負責大廳服務；`RoomProcessor.*` 與 `RoomProto.tars` 處理比賽房間和成員；`UserInfoProcessor.*` 處理玩家資料。專案不是 Node.js 專案，請勿使用舊版 README 的 npm 指令。編譯前需準備 Tars、Protobuf、MySQL 及倉庫未包含的公共協議/模組。

## 聯絡與核驗

Telegram：[@xuzongbin001](https://t.me/xuzongbin001) · Email：masterai918@gmail.com

請在使用前核對演示、源碼範圍、第三方相依、智慧財產權和當地法規。本倉庫不構成收益、搜尋排名或上線承諾。
