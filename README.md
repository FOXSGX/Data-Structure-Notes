# Data Structure

这个目录用于存放数据结构课程练习代码，目前主要使用 C++ 模板实现基础线性结构。

## 目录结构

```text
.
├── Class01 LinearList
│   ├── include
│   │   ├── LinearList.h
│   │   ├── List.h
│   │   ├── SeqList.h
│   │   ├── SeqList.tpp
│   │   ├── CircList.h
│   │   └── CircList.tpp
│   └── test
│       ├── test_SeqList.cpp
│       └── test_CircList.cpp
└── CLass02
    ├── include
    │   ├── Stack.h
    │   └── Stack.tpp
    └── test
        └── test_Stack.cpp
```

## 已实现内容

- `SeqList<T>`：顺序表，支持插入、删除、查找、输出、拷贝和移动。
- `CircList<T>`：循环单链表，支持头尾插入、头尾删除、访问头尾元素、拷贝和移动。
- `Stack<T>`：基于 `std::vector` 的栈，支持入栈、出栈、访问栈顶和容量查询。

## 编译测试

在当前目录执行：

```bash
clang++ -std=c++17 -Wall -Wextra -Wpedantic -I"Class01 LinearList/include" \
  "Class01 LinearList/test/test_SeqList.cpp" -o /tmp/test_seqlist && /tmp/test_seqlist

clang++ -std=c++17 -Wall -Wextra -Wpedantic -I"Class01 LinearList/include" \
  "Class01 LinearList/test/test_CircList.cpp" -o /tmp/test_circlist && /tmp/test_circlist

clang++ -std=c++17 -Wall -Wextra -Wpedantic -I"CLass02/include" \
  "CLass02/test/test_Stack.cpp" -o /tmp/test_stack && /tmp/test_stack
```

## 说明

模板类的实现放在 `.tpp` 文件中，并由对应的 `.h` 文件包含。因此使用时只需要包含头文件，例如：

```cpp
#include "SeqList.h"
#include "CircList.h"
#include "Stack.h"
```
