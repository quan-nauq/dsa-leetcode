# Majority Element

[LeetCode 169](https://leetcode.com/problems/majority-element/) · Easy · Arrays & Hashing

## The problem

Given a list of numbers, return the one that appears **more than half the
time**. The problem guarantees such a number exists.

## The simple way first

Count every number with a hash map, then return the one with the biggest count.
Same idea as [Contains Duplicate](../contains-duplicate/). It's O(n) time but
O(n) extra space. Can we skip the map?

## The idea

Think of it as an election where numbers fight each other.

- Keep one **candidate** and a **count** of its lead.
- See the candidate again → count goes up (a vote for it).
- See something else → count goes down (a vote against it).
- Count hits 0 → the candidate has been cancelled out. The current number
  becomes the new candidate.

The majority number appears more than half the time, so **it can't be fully
cancelled out**. Everyone else combined has fewer votes than it does. Whatever
candidate is left standing at the end is the majority.

## Walkthrough

`nums = [2, 2, 1, 1, 1, 2, 2]`

| num | candidate | count after         |
|-----|-----------|---------------------|
| 2   | 2         | 1 (start)           |
| 2   | 2         | 2                   |
| 1   | 2         | 1                   |
| 1   | 2 → **1** | 0, so switch → 1    |
| 1   | 1         | 2                   |
| 2   | 1         | 1                   |
| 2   | 1 → **2** | 0, so switch → 1    |

Answer: **2**. The candidate changed twice along the way, but the true
majority always wins in the end.

## Why it needs the guarantee

The algorithm returns whoever is left standing, and it never checks that they
actually appear more than half the time. On `[1, 2, 3]` it returns something
anyway. It's only correct because this problem promises a majority exists.

## Complexity

- **Time:** O(n) — one pass
- **Space:** O(1) — just a candidate and a count

## Solutions

- [Python](solution.py)
- [C++](solution.cpp)