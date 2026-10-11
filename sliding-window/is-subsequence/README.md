# Is Subsequence

[LeetCode 392](https://leetcode.com/problems/is-subsequence/) · Easy · Two Pointers

## The problem

Given two strings `s` and `t`, return `true` if `s` can be made by deleting
some letters from `t` **without changing the order** of the rest.

`"ace"` is a subsequence of `"abcde"`. `"aec"` is not, because the order is
wrong.

## The idea

Walk through `t` once, and use `s` as a checklist of letters to find, in order.

Two pointers:

- **i** points at the next letter of `s` we still need
- **j** walks through `t`, one letter at a time

At each step:

- `t[j]` matches `s[i]` → tick that letter off, move `i` forward
- No match → ignore this letter of `t`
- Either way, move `j` forward

If `i` reaches the end of `s`, every letter was found, in order, so return
`true`. If `t` runs out first, some letter was never found, so return `false`.

## Walkthrough

`s = "abc"`, `t = "ahbgdc"`

| j | t[j] | Looking for (s[i]) | Match? | i after |
|---|------|--------------------|--------|---------|
| 0 | a    | a                  | yes    | 1       |
| 1 | h    | b                  | no     | 1       |
| 2 | b    | b                  | yes    | 2       |
| 3 | g    | c                  | no     | 2       |
| 4 | d    | c                  | no     | 2       |
| 5 | c    | c                  | yes    | 3       |

`i` reached 3, the length of `s`, so the answer is `true` ✓

## Why order is kept

`i` only ever moves forward, and `j` only ever moves forward. A letter in `s`
can only be matched by a letter in `t` that comes **after** the previous match.
That is exactly the "same relative order" rule.

## Edge cases

- **`s` is empty:** the loop never runs and `i == len(s)` is already true, so
  an empty string is a subsequence of anything.
- **`s` longer than `t`:** `t` runs out first, so `i` can't reach the end and
  the answer is `false`. No special check needed.

## Complexity

- **Time:** O(m), one pass through `t`
- **Space:** O(1), just two pointers

## Solutions

- [Python](solution.py)
- [C++](solution.cpp)