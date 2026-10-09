# Move Zeroes

[LeetCode 283](https://leetcode.com/problems/move-zeroes/) · Easy · Two Pointers

## The problem

Given a list of numbers, move every `0` to the end. The non-zero numbers must
keep their original order. Do it **in place**, without making a second list.

## The idea

The problem only cares about the order of the **non-zero** numbers. The zeroes
are all identical, so their order means nothing. That lets us split the job in two:

1. Move the non-zero numbers to the front, in the order we meet them.
2. Fill whatever space is left at the back with zeros.

We use two positions:

- **read**: the loop, looking at every number once
- **write**: the next spot where a non-zero number should go (starts at 0)

For each number:

- It's a zero → skip it. `write` doesn't move.
- It's non-zero → copy it into `write`, then move `write` forward by one.

The earlier a non-zero number is met, the closer to the front it lands, so the
original order is kept. When the loop ends, `write` is the count of non-zero
numbers. Every spot from `write` to the end gets a zero.

## Walkthrough

`nums = [0, 1, 0, 3, 12]`

| num read | action              | write after | array after          |
|----------|---------------------|-------------|----------------------|
| 0        | skip                | 0           | [0, 1, 0, 3, 12]     |
| 1        | copy to position 0  | 1           | [1, 1, 0, 3, 12]     |
| 0        | skip                | 1           | [1, 1, 0, 3, 12]     |
| 3        | copy to position 1  | 2           | [1, 3, 0, 3, 12]     |
| 12       | copy to position 2  | 3           | [1, 3, 12, 3, 12]    |

Now fill from position 3 to the end with zeros:

    [1, 3, 12, 0, 0]  ✓

The middle of the table looks messy (duplicate 1s, 3s and 12s), but those
leftovers are exactly the spots the final step overwrites with zeros.

## Why overwriting is safe

We never copy over a number we haven't read yet. `write` can never get ahead
of the number being read: it only moves forward when we find a non-zero, and
we read first. So every spot we overwrite has already been looked at.

## Complexity

- **Time:** O(n), one pass to copy and one pass to fill zeros
- **Space:** O(1), the work happens inside the original list

## Solutions

- [Python](solution.py)
- [C++](solution.cpp)