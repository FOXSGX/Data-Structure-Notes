# Data Structure

数据结构课程：课堂作业、课后复现、原始资料与学习知识库。

## 目录

| 路径 | 用途 |
|---|---|
| `coursework/assignments/` | 课堂作业与提交测试 |
| `practice/` | 课后自主复现（C++） |
| `resources/` | 教材、课件、试卷原件，不复制进知识库 |
| `vault/` | 事实记忆层，同时是唯一的 Obsidian Vault |

## 已实现

- `SeqList`：顺序表；`CircList`：循环单链表；`Stack`：基于 `std::vector` 的栈。
- `BinaryTree`：二叉树，前序建树（`Refvalue` 表示空）、前/中/后/层次遍历、清空。

模板类实现在 `.tpp`，由对应 `.h` 包含，使用时只需 `#include` 头文件。

## 编译测试

```bash
./run.sh "practice/Tree/test_tree.cpp"      # 参数为任意 test_*.cpp
```

手动编译示例（与 `run.sh` 等效）：

```bash
clang++ -std=c++17 -Wall -Wextra -Wpedantic -I"practice/Tree" \
  "practice/Tree/tree.cpp" "practice/Tree/test_tree.cpp" -o /tmp/test_tree && /tmp/test_tree
```
