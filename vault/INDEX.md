---
title: 事实记忆索引
type: vault-index
updated: "2026-09-23"
---

# 事实记忆索引

`vault/` 是持久化事实记忆层，不等同于知识库。它保存项目事实、过程记录和稳定知识，并通过目录明确区分用途。

## 分区

| 目录 | 保存什么 | 不保存什么 |
|---|---|---|
| [projects/data-structure](projects/data-structure) | 数据结构项目的目标、学习状态和知识缺口 | 通用概念正文 |
| [notes](notes) | 工作日志、会话交接和暂时性的过程记录 | 已经稳定的领域知识 |
| [kb](kb) | 可复用的概念、来源、实验和复习知识 | 只对某一次会话有意义的状态 |

## 当前项目

- 项目入口：[INDEX.md](../INDEX.md)
- 当前任务：[TODOS.md](../TODOS.md)
- 学习目标：[projects/data-structure/GOAL.md](projects/data-structure/GOAL.md)
- 当前缺口：[projects/data-structure/GAPS.md](projects/data-structure/GAPS.md)
- 最近工作记录：[notes/WORKLOG.md](notes/WORKLOG.md)
- 稳定知识入口：[kb/首页.md](kb/首页.md)

## 写入判断

- “项目现在是什么状态？”写入 `projects/`。
- “这次做了什么、为什么改？”写入 `notes/`。
- “以后换一个项目仍可复用的理解是什么？”写入 `kb/`。
