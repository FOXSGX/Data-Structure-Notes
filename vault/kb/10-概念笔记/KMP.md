---
title: KMP
type: concept
date: "2026-09-29"
domain: 数据结构
mastery: L2-能推演
tags:
  - 课程/数据结构
sources:
  - "[[SOURCES]]"
---

# KMP

## 教材的 `next` 约定

使用从 0 开始的下标。`next[0] = -1`；当模式串第 `j` 个字符失配时，`next[j]` 是模式串应回退到的下标。对 `j > 0`，它等于已匹配部分 `P[0..j-1]` 的最长相等真前缀与后缀的长度。

构造时，已知当前候选长度 `k`，若新字符能延长相等前后缀，就记录 `k + 1`；否则沿 `next[k]` 尝试更短候选。搜索失配时主串下标不回退。教材《数据结构：用面向对象方法与 C++ 语言描述》（第 2 版）第 165–167 页使用此约定。

## 本轮实现与验证

- 用户独立实现：[KMP.cpp](<../../../practice/Class03 Array&String/KMP.cpp>)；现有练习文件：[text_KMP.cpp](<../../../practice/Class03 Array&String/test/text_KMP.cpp>)。
- 首次用 Visual Studio 2022 地址检查器运行时，在 `buildNEXT` 写入 `next[size]` 处报告越界；用户随后修正循环边界，并补充空模式串返回 0。
- 2026-09-29 重新以 `cl /std:c++17 /EHsc /W4 /utf-8 /fsanitize=address` 编译，临时验证教材示例 `next("abaabcac") = [-1,0,0,1,1,2,0,1]`、`kmp_find("aaaaab", "aaab") = 2`、模式串过长返回 -1、空模式串返回 0；退出码 0，地址检查器未报告错误。临时验证文件不属于项目产物。
- 编译仍有 `int` 与 `size_t` 比较警告。用户表示本轮不再处理测试文件；掌握等级暂留 L2，后续需新情境迁移与用户最终验证。
