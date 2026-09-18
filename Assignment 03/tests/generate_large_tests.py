from pathlib import Path


N = 300_000
TEST_DIR = Path(__file__).resolve().parent


def write_case(name: str, permutation: list[int], expected: str) -> None:
    (TEST_DIR / f"{name}.in").write_text(
        f"{len(permutation)}\n{' '.join(map(str, permutation))}\n",
        encoding="utf-8",
    )
    (TEST_DIR / f"{name}.out").write_text(f"{expected}\n", encoding="utf-8")


write_case("90_large_identity", list(range(1, N + 1)), "YES")
write_case("91_large_reverse", list(range(N, 0, -1)), "YES")
write_case("92_large_impossible", [N, *range(1, N)], "NO")

print(f"Generated 3 large tests in {TEST_DIR}")
