# 测试说明

每个 `.in` 文件对应同名的 `.out` 文件。题目一次只接收一组数据，
因此这些用例需要分别运行。

| 用例 | 覆盖内容 |
| --- | --- |
| `01_single` | 最小规模 |
| `02_identity` | 完全顺序输出 |
| `03_reverse` | 全部入栈后逆序输出 |
| `04_sample_yes` | 题目样例 1 |
| `05_sample_no` | 题目样例 2 |
| `06_pair_swaps` | 连续的两两交换 |
| `07_nested_blocks` | 多段较深的连续出栈 |
| `08_mixed_yes` | 长短出栈段混合的可行情形 |
| `09_smallest_no` | 最小的不可行情形 |
| `10_middle_blocked` | 在序列中部被栈顶阻塞 |
| `11_deep_blocked` | 较深位置被阻塞 |
| `12_deceptive_yes` | 看似乱序但实际可行 |
| `13_late_failure` | 很长的合法前缀后才失败 |

`generate_large_tests.py` 可额外生成 `n = 300000` 的三个压力测试，
分别覆盖顺序、逆序以及不可行排列：

```bash
python3 tests/generate_large_tests.py
```
