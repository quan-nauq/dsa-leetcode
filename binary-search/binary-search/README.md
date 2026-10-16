# Binary Search

[LeetCode 704](https://leetcode.com/problems/binary-search/) · Easy · Binary Search

## The problem

Given a list of numbers sorted from smallest to biggest, and a `target`, return
the index of the target, or `-1` if it isn't there.

## The simple way first

Check every number from the left until you find the target. It works, but it's
O(n): a list of a million numbers can take a million checks.

## The idea

The list is **sorted**, and that's the whole trick. Look at the middle number:

- It equals the target → done, return its index.
- It's **smaller** than the target → the target can only be on the right, so
  throw away the left half (and the middle).
- It's **bigger** than the target → the target can only be on the left, so
  throw away the right half (and the middle).

Repeat on what's left. Two pointers, `left` and `right`, mark the search area.
Each step cuts it in half. If the area becomes empty (`left > right`), the
target isn't in the list.

It's like guessing a number from 1 to 100: guess 50, hear "higher", and you
never look at 1 to 50 again.

## Walkthrough

`nums = [-1, 0, 3, 5, 9, 12]`, `target = 9`

| left | right | mid | nums[mid] | Action |
|------|-------|-----|-----------|--------|
| 0 | 5 | 2 | 3 | 3 < 9, drop left: left = 3 |
| 3 | 5 | 4 | 9 | found → return **4** ✓ |

Two steps instead of up to six.

When the target is missing, `target = 2`:

| left | right | mid | nums[mid] | Action |
|------|-------|-----|-----------|--------|
| 0 | 5 | 2 | 3 | 3 > 2, drop right: right = 1 |
| 0 | 1 | 0 | -1 | -1 < 2, drop left: left = 1 |
| 1 | 1 | 1 | 0 | 0 < 2, drop left: left = 2 |

Now `left = 2 > right = 1`, so the area is empty → return **-1** ✓

## The details that cause bugs

- **`mid + 1` and `mid - 1`:** we already checked `mid`, so the new area must
  exclude it. Writing `left = mid` can loop forever.
- **`left <= right` (not `<`):** when they're equal there's still one number
  left to check.
- **`mid = left + (right - left) // 2`:** gives the same middle as
  `(left + right) // 2`, but can't overflow in C++ when the numbers are huge.
  Python doesn't have that problem, but it's a good habit.

## Edge cases

- **Empty list:** `right` is -1, the loop never runs, returns `-1`.
- **One number:** `left == right`, so it gets checked once.
- **Target smaller or bigger than everything:** the area shrinks to empty and
  returns `-1`.

## Complexity

- **Time:** O(log n), halving a million numbers takes about 20 steps
- **Space:** O(1), just three integers

## Solutions

- [Python](solution.py)
- [C++](solution.cpp)