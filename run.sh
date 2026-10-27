#!/usr/bin/env bash
# 用法: ./run.sh <任意 test_*.cpp 路径>
set -e
f="${1:?用法: ./run.sh practice/Tree/test_tree.cpp}"
d=$(dirname "$f")
SDK=/Library/Developer/CommandLineTools/SDKs/MacOSX15.sdk
[ -d "$SDK" ] || SDK=$(xcrun --show-sdk-path)
extra=$(grep -L 'int main' "$d"/*.cpp 2>/dev/null || true)
clang++ -std=c++17 -Wall -Wextra -g -isysroot "$SDK" -I"$d" -I"$d/../include" "$f" $extra -o "$d/a.out"
"$d/a.out"
