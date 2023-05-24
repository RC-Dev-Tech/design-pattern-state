# ![](https://drive.google.com/uc?id=10INx5_pkhMcYRdx_OO4rXNXxcsvPtBYq) State 狀態模式   
> ##### 理論請自行找，網路上有很多相關的文章，這邊只關注於範例實作的部分.

---

<!--ts-->
## 目錄
* [目的](#目的)
* [使用時機](#使用時機)
* [URL結構圖](#url結構圖)
* [實作成員](#實作成員)
* [實作範例](#實作範例)
* [參考資料](#參考資料)
<!--te-->

---

## 目的
State是一個行為型設計模式，它允許物件在其內部狀態發生變化時改變它的行為，從而使物件看起來像是改變了它的類別。

---

## 使用時機
當一個物件的行為需要隨著其內部狀態的變化而變化時，可以使用State模式。<br>
它可以幫助我們在不同的狀態下改變物件的行為，而不需要使用過多的條件語句或switch語句。

---

## URL結構圖
![](https://drive.google.com/uc?id=1RlLoKz6yd-OJY0VtAADPmIEjCSI5VvvX)
> 圖片來源：[Refactoring.Guru - State](https://refactoring.guru/design-patterns/state)

---

## 實作成員
* Context
  * 定義客戶端所感興趣的接口。維護一個State子類實例，該實例表示上下文的當前狀態。
* State
  * 定義一個介面，用於封裝與Context相關的行為。
* ConcreteState
  * 實現State介面，並根據Context當前的狀態來實現相應的行為。

---

## 實作範例:
- [Example](https://github.com/RC-Dev-Tech/design-pattern-state/blob/main/C%2B%2B/main.cpp) - State Pattern (C++) 

---

## 參考資料
* [Wiki - State Pattern](https://en.wikipedia.org/wiki/State_pattern) <br>
* [Refactoring.Guru - State](https://refactoring.guru/design-patterns/state) <br>

---

<!--ts-->
#### [目錄 ↩](#目錄)
<!--te-->
---
