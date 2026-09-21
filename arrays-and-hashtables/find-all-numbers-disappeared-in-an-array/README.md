# Find All Numbers Disappeared in an Array

[LeetCode 448](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/) · Easy · Arrays & Hashing

## The problem

You get a list of `n` numbers, each between 1 and `n`. Some numbers show up
more than once, which means others are missing. Return every number from 1 to
`n` that never appears.

## The simple way first

Put every number into a set, then loop from 1 to `n` and collect whatever isn't
in the set. Same idea as [Contains Duplicate](../contains-duplicate/).

It works, but the set costs O(n) extra memory. The follow-up asks: can we do it
without that?

## The idea

The problem hands us a key fact: **every number is between 1 and `n`**, and the
array has exactly `n` positions (0 to `n - 1`).

So every number has its own position:

    number v  →  position v - 1     (minus 1 because arrays start at 0)

That means the array can be its own "seen" list. Every time we meet a number,
we **mark its position** by making the value there negative.

At the end:

- position still **negative** → that number showed up
- position still **positive** → nobody marked it, so `position + 1` is missing

## Walkthrough

`nums = [4, 3, 2, 7, 8, 2, 3, 1]`

| num read | mark position | array after                       |
|----------|---------------|-----------------------------------|
| 4        | 3             | [4, 3, 2, **-7**, 8, 2, 3, 1]     |
| 3        | 2             | [4, 3, **-2**, -7, 8, 2, 3, 1]    |
| -2 → 2   | 1             | [4, **-3**, -2, -7, 8, 2, 3, 1]   |
| -7 → 7   | 6             | [4, -3, -2, -7, 8, 2, **-3**, 1]  |
| 8        | 7             | [4, -3, -2, -7, 8, 2, -3, **-1**] |
| 2        | 1             | already negative, stays           |
| -3 → 3   | 2             | already negative, stays           |
| -1 → 1   | 0             | [**-4**, -3, -2, -7, 8, 2, -3, -1] |

Still positive: positions **4** and **5** → missing numbers **5** and **6**.

## Why `abs` shows up twice

1. **`abs(num)` when reading.** Earlier marks may have already turned the
   number we're reading negative (like the `-2` in step 3). We still need its
   real value to find its position.
2. **`-abs(...)` when marking.** If a number appears twice, we mark the same
   position twice. Writing `-abs(x)` keeps it negative instead of flipping it
   back to positive.

## Trade-off

This changes the input array: it comes back full of negatives. That's the price
of using no extra memory. Fine on LeetCode, but in real code you'd tell whoever
calls the function.

## Complexity

- **Time:** O(n) — two passes over the array
- **Space:** O(1) extra — the marks live in the input array (the answer list
  doesn't count)

## Solutions

- [Python](solution.py)
- [C++](solution.cpp)