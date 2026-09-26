---
title: 数据结构项目索引
type: project-index
updated: "2026-09-23"
---

# 数据结构项目索引

这是人和 AI 进入项目时共同阅读的入口。它只负责说明“资料在哪里、包含什么、什么时候读”，不复制正文。

## 建议阅读顺序

1. [TODOS.md](TODOS.md)：当前学习目标和下一步。
2. [vault/projects/data-structure/GOAL.md](vault/projects/data-structure/GOAL.md)：成功标准和掌握等级。
3. [数据结构主题索引](vault/kb/20-主题索引/数据结构.md)：概念之间的关系。
4. 当前概念笔记及其来源、代码、测试和实验。
5. [vault/projects/data-structure/GAPS.md](vault/projects/data-structure/GAPS.md)：复习前检查是否有重复错误。

## 项目地图

| 位置 | 内容 | 什么时候读 |
|---|---|---|
| [README.md](README.md) | 当前实现概览和编译命令 | 初次进入项目，或需要运行测试时 |
| [TODOS.md](TODOS.md) | 当前任务、待确认事项和完成记录 | 每次学习开始与结束时 |
| [vault/INDEX.md](vault/INDEX.md) | 事实记忆层的入口与分区说明 | 需要查项目状态、日志或知识时 |
| [vault/kb/首页.md](vault/kb/首页.md) | 稳定知识库入口 | 在 Obsidian 中学习和复习时 |
| [vault/projects/data-structure/GOAL.md](vault/projects/data-structure/GOAL.md) | 学习目标、交付物、掌握等级 | 选择学习内容或判断是否学会时 |
| [vault/projects/data-structure/GAPS.md](vault/projects/data-structure/GAPS.md) | 当前学习缺口和重复错误 | 复习、出题和调整路线时 |
| [vault/kb/SOURCES.md](vault/kb/SOURCES.md) | 教材及证据层级 | 查证事实或发生冲突时 |
| [vault/notes/WORKLOG.md](vault/notes/WORKLOG.md) | 重要学习与项目变更的简短日志 | 新会话需要恢复上下文时 |
| [coursework/assignments](coursework/assignments) | 课堂作业、提交代码和作业测试 | 完成课程要求或检查迁移能力时 |
| [practice](practice) | 课后自主复现及其测试 | 学习实现、不变量和边界条件时 |
| [resources](resources) | 教材、课件等原始资料 | 查证概念和教材约定时 |

## 实现与测试

### 线性表

- `SeqList<T>`：顺序存储的线性表。
  - [接口](<practice/Class01 LinearList/include/SeqList.h>)
  - [实现](<practice/Class01 LinearList/include/SeqList.tpp>)
  - [测试](<practice/Class01 LinearList/test/test_SeqList.cpp>)
- `CircList<T>`：循环单链表。
  - [接口](<practice/Class01 LinearList/include/CircList.h>)
  - [实现](<practice/Class01 LinearList/include/CircList.tpp>)
  - [测试](<practice/Class01 LinearList/test/test_CircList.cpp>)

当学习“表示方式、不变量、插入删除和复杂度比较”时阅读。

### 栈

- `Stack<T>`：基于 `std::vector` 的栈。
  - [接口](<practice/Class02 Stack&Queue/include/Stack.h>)
  - [实现](<practice/Class02 Stack&Queue/include/Stack.tpp>)
  - [测试](<practice/Class02 Stack&Queue/test/test_Stack.cpp>)

当学习 LIFO、不变量、栈序列或相关作业时阅读。

### 作业

- `coursework/assignments/Assignment 01`、`Assignment 02`：课程早期练习。
- `coursework/assignments/Assignment 03`：包含实现及系统化输入输出测试；先读[测试说明](<coursework/assignments/Assignment 03/tests/README.md>)。

作业是迁移能力和边界意识的证据，不替代概念解释。

## 来源

- `resources/textbook/`：本地课程教材 PDF，详见 [vault/kb/SOURCES.md](vault/kb/SOURCES.md)。
- `resources/slides/`：按章节保存的课程课件。
- `tmp/`：教材提取和渲染的临时结果，可重新生成，不作为权威来源。

## 维护原则

- 新增重要资料时，为它补充“内容”和“什么时候读”。
- 当前状态写入 `TODOS.md` 和 `vault/projects/`，稳定知识只写入 `vault/kb/`，不要把聊天记录当长期记忆。
- 只有真实重复出现的工作流，才进一步固化为 Skill。
