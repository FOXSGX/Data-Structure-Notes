# Data Structure

这个目录同时保存数据结构课程作业、课后复现练习、原始资料和学习知识库。目前的复现练习主要使用 C++ 模板实现基础线性结构。

## 目录结构

```text
.
├── coursework
│   └── assignments          # 课堂作业与提交测试
├── practice                 # 课后自主复现
│   ├── Class01 LinearList
│   │   ├── include
│   │   └── test
│   └── Class02 Stack&Queue
│       ├── include
│       └── test
├── resources
│   ├── textbook             # 原始教材 PDF
│   └── slides               # 课程课件
└── vault
    ├── projects             # 项目目标与学习状态
    ├── notes                # 工作过程记录
    └── kb                   # 稳定知识、来源笔记、实验与复习
```

## 已实现内容

- `SeqList<T>`：顺序表，支持插入、删除、查找、输出、拷贝和移动。
- `CircList<T>`：循环单链表，支持头尾插入、头尾删除、访问头尾元素、拷贝和移动。
- `Stack<T>`：基于 `std::vector` 的栈，支持入栈、出栈、访问栈顶和容量查询。

## 编译测试

在当前目录执行：

```bash
clang++ -std=c++17 -Wall -Wextra -Wpedantic -I"practice/Class01 LinearList/include" \
  "practice/Class01 LinearList/test/test_SeqList.cpp" -o /tmp/test_seqlist && /tmp/test_seqlist

clang++ -std=c++17 -Wall -Wextra -Wpedantic -I"practice/Class01 LinearList/include" \
  "practice/Class01 LinearList/test/test_CircList.cpp" -o /tmp/test_circlist && /tmp/test_circlist

clang++ -std=c++17 -Wall -Wextra -Wpedantic -I"practice/Class02 Stack&Queue/include" \
  "practice/Class02 Stack&Queue/test/test_Stack.cpp" -o /tmp/test_stack && /tmp/test_stack
```

## 说明

模板类的实现放在 `.tpp` 文件中，并由对应的 `.h` 文件包含。因此使用时只需要包含头文件，例如：

```cpp
#include "SeqList.h"
#include "CircList.h"
#include "Stack.h"
```
