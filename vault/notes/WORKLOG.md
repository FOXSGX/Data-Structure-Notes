---
title: 数据结构工作日志
type: worklog
updated: "2026-11-10"
---

# 数据结构工作日志

只记录会帮助下一次会话恢复上下文的重要变化，并链接到实际产物。

## 2026-11-10：目录与 Obsidian 配置精简

- 扁平化记忆层：`kb/10-概念笔记`→`kb/概念笔记`、`20-主题索引`→`kb/主题索引`、`90-模板`→`kb/模板`。
- 删除空目录 `00-收件箱`、`30-复习记录`；实验索引并入[知识首页](../kb/首页.md)，教材索引并入 [SOURCES](../kb/SOURCES.md)。
- 入口合并：根 `TODOS.md` 与 `vault/INDEX.md` 的内容并入 [INDEX.md](../../INDEX.md)，全项目只保留一个入口。
- Obsidian 唯一 Vault 由项目根改为 `vault/`（与离散数学项目一致）；根目录旧 `.obsidian` 归档到 `.archive/obsidian-root-config-20261110/`。链接格式设为 shortest 并自动更新，模板目录改为 `kb/模板`，`app.json` 排除 `notes/`、`projects/`、`kb/首页.md`、`kb/主题索引/` 以免污染图谱和搜索。
- 上下文预算：每次会话必读由 AGENTS + INDEX + TODOS 约 8.7 KB 降到约 3 KB；README 只保留目录与编译命令。
- 验证：Markdown 相对链接、wiki 链接、Obsidian JSON 全部检查通过；`practice/` 代码未改动。

## 2026-10-27：整理学长标注的章节重点

- 把课程 PDF「课程内容（一）（二）」页上标红的部分整理为[章节重点（学长标注）](../projects/data-structure/章节重点（学长标注）.md)，并确认第五章第 5、7、8 部分为重点。

## 2026-09-23：初始化 AI + Obsidian 学习系统

- 将项目根目录设为唯一 Obsidian Vault（2026-11-10 起改为 `vault/`）；`vault/` 是事实记忆层，只有 `vault/kb/` 保存稳定知识。
- 新增项目入口 [INDEX.md](../../INDEX.md) 和状态文件 `TODOS.md`（2026-11-10 已并入 INDEX）。
- 建立项目事实 [[GOAL]]、[[GAPS]] 与知识来源 [[SOURCES]]，分离状态和稳定知识。
- 新增实验、来源和复习模板；没有安装社区插件或建立复杂检索。
- 修正记忆层级：`vault/projects/` 保存项目事实，`vault/notes/` 保存过程，只有 `vault/kb/` 保存稳定知识。
- 现有 [[字符串]] 笔记保持原始学习与纠错内容不变。
- 整理工作产物：课堂作业移动到 `coursework/assignments/`，课后复现移动到 `practice/`。
- 整理原始资料：教材移动到 `resources/textbook/`，课件集中到 `resources/slides/`；知识库只保存来源索引和消化后的笔记。
- 更新全部索引、来源链接和编译命令；顺序表、循环链表和栈的测试均在新路径下编译运行成功。
