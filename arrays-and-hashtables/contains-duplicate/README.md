# Contains Duplicate

[LeetCode 217](https://leetcode.com/problems/contains-duplicate/) · Easy · Arrays & Hashing

## The problem

Given a list of numbers, return `true` if any number appears more than once,
and `false` if every number is unique.

## The idea

Walk through the list once and remember every number you've seen.

For each new number, ask one question: **have I seen this before?**

- Yes → that's a duplicate. Stop and return `true`.
- No → remember it, move on.

If you reach the end without ever answering "yes", every number was unique,
so return `false`.

## Walkthrough

`nums = [3, 1, 4, 1]`

| Step | num | Seen before? | Set after          |
|------|-----|--------------|--------------------|
| 1    | 3   | no           | {3}                |
| 2    | 1   | no           | {3, 1}             |
| 3    | 4   | no           | {3, 1, 4}          |
| 4    | 1   | **yes**      | stop → `true`      |

## Why a set?

The whole solution depends on asking "have I seen this?" quickly.

- Keep seen numbers in a **list**, and checking means scanning the whole list
  every time. That's slow.
- Keep them in a **set**, and checking is instant (on average), no matter how
  many numbers are stored.

The simpler alternative (brute-force), comparing every number with every other number,
works too, but for a list of 10,000 numbers that's about 50 million comparisons.
The set version does 10,000 checks.

## Complexity

- **Time:** O(n) — each number is looked at once
- **Space:** O(n) — in the worst case (no duplicates) every number goes in the set

## Solutions

- [Python](solution.py)
- [C++](solution.cpp)