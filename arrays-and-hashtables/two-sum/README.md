# Two Sum

[LeetCode 1](https://leetcode.com/problems/two-sum/) · Easy · Arrays & Hashing

## The problem

Given a list of numbers and a target, find the two numbers that add up to the
target and return their positions (indices). There is always exactly one answer,
and you can't use the same element twice.

## The idea

Same trick as [Contains Duplicate](../contains-duplicate/): walk through the
list once and remember what you've seen.

The difference is the question you ask. For each number, you already know what
its partner must be:

    partner = target - current number

So instead of asking "have I seen *this* number?", ask **"have I seen its
partner?"**

- Yes → found the pair. Return both positions.
- No → remember this number and its position, move on.

Since the problem guarantees exactly one pair exists, you'll always find it
before the loop ends.

## Walkthrough

`nums = [2, 7, 11, 15]`, `target = 9`

| i | num | partner (9 − num) | Partner seen? | Map after      |
|---|-----|-------------------|---------------|----------------|
| 0 | 2   | 7                 | no            | {2: 0}         |
| 1 | 7   | 2                 | **yes, at 0** | stop → `[0, 1]` |

## Why a map, not a set?

In Contains Duplicate we only needed to know *whether* we'd seen a number, so a
set was enough. Here we need to know *where* we saw it, because the answer is
positions. A map stores both: number → index.

## Why check before inserting?

Order matters. Try `nums = [3, 2, 4]`, `target = 6`.

If you insert first, then check:

| i | num | insert  | partner | Found?                              |
|---|-----|---------|---------|-------------------------------------|
| 0 | 3   | {3: 0}  | 3       | **yes, at 0** → `[0, 0]` ✗ wrong    |

The 3 found *itself*. Using the same element twice isn't allowed.

Checking first, the map only ever holds numbers from *earlier* positions, so a
number can never pair with itself:

| i | num | partner | Partner seen? | Map after        |
|---|-----|---------|---------------|------------------|
| 0 | 3   | 3       | no            | {3: 0}           |
| 1 | 2   | 4       | no            | {3: 0, 2: 1}     |
| 2 | 4   | 2       | **yes, at 1** | stop → `[1, 2]` ✓ |

## Complexity

- **Time:** O(n) — each number is looked at once
- **Space:** O(n) — in the worst case almost every number goes in the map

## Solutions

- [Python](solution.py)
- [C++](solution.cpp)