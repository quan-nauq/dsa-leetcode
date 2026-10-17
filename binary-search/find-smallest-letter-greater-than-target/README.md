# Find Smallest Letter Greater Than Target

[LeetCode 744](https://leetcode.com/problems/find-smallest-letter-greater-than-target/) · Easy · Binary Search

## The problem

Given a sorted list of letters and a `target` letter, return the smallest letter
that is **strictly bigger** than the target. The list wraps around: if no
letter is bigger, return the first letter.

    letters = ["c", "f", "j"], target = "c"   →   "f"
    letters = ["c", "f", "j"], target = "j"   →   "c"  (wraps around)

## The simple way first

Scan from the left and return the first letter bigger than the target. If you
reach the end, return the first letter. It works, but it's O(n).

## The idea

The list is sorted, so we can binary search, like in
[Binary Search](../binary-search/). The difference: there's nothing to
"find". We're looking for a **boundary**: the point where letters stop being
`<= target` and start being `> target`.

Look at the middle letter:

- `letters[mid] > target` → mid could be the answer, but an earlier letter
  might also be bigger, so drop the right side: `right = mid - 1`.
- `letters[mid] <= target` → mid is too small (equal doesn't count, the answer
  must be strictly bigger), so drop the left side: `left = mid + 1`.

We never stop early on a match. We keep squeezing until `left > right`.

## Why `left` is the answer

Two facts stay true the whole time:

- everything **left of `left`** is `<= target`
- everything **right of `right`** is `> target`

When the loop ends, `left = right + 1`: the two groups touch. So `left` is the
first letter in the "bigger" group, which is exactly what we want.

## The wrap-around

If every letter is `<= target`, `left` ends up at `n`, one past the last
index. `left % n` turns `n` into `0`, which is the first letter. In every other
case `left < n`, so the `%` changes nothing.

## Walkthrough

`letters = ["c", "f", "j"]`, `target = "c"`

| left | right | mid | letters[mid] | Action |
|------|-------|-----|--------------|--------|
| 0 | 2 | 1 | f | f > c, right = 0 |
| 0 | 0 | 0 | c | c is not > c, left = 1 |

`left = 1 > right = 0`, so stop. Answer: `letters[1]` = **"f"** ✓

Wrap-around, `target = "j"`:

| left | right | mid | letters[mid] | Action |
|------|-------|-----|--------------|--------|
| 0 | 2 | 1 | f | f is not > j, left = 2 |
| 2 | 2 | 2 | j | j is not > j, left = 3 |

`left = 3`, and `3 % 3 = 0`, so the answer is `letters[0]` = **"c"** ✓

## Edge cases

- **Duplicates (`["a", "b", "b", "c"]`, target `"b"`):** equal letters go the
  `<= target` way, so we skip past all copies of `b` and land on `c`.
- **Target smaller than everything:** every mid is bigger, `left` stays 0,
  returns the first letter.
- **One letter:** one check, then either `left = 0` or wraps to 0, so it
  returns that letter.

## Complexity

- **Time:** O(log n), the search area halves every step
- **Space:** O(1), a few integers

## Solutions

- [Python](solution.py)
- [C++](solution.cpp)