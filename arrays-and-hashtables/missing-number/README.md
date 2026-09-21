# Missing Number

[LeetCode 268](https://leetcode.com/problems/missing-number/) · Easy · Arrays & Hashing

## The problem

You get `n` different numbers, all from the range 0 to `n`. That range has
`n + 1` numbers, so exactly one is missing. Find it.

## The idea

If nothing were missing, the numbers would be 0, 1, 2, ..., n. We know what
those add up to. Add up what we actually have, and the difference is the
missing number.

    missing = (sum of 0 to n) − (sum of nums)

In the code we do this as a countdown: start with the full sum, subtract every
number we see, and whatever's left is the one that never showed up.

## Walkthrough

`nums = [3, 0, 1]`, so `n = 3`

Full sum of 0 to 3: 0 + 1 + 2 + 3 = **6**

| num | total after subtracting |
|-----|-------------------------|
| —   | 6                       |
| 3   | 3                       |
| 0   | 3                       |
| 1   | **2**                   |

Answer: **2**.

## Where the formula comes from

Adding 1 to n one number at a time would work, but there's a shortcut:

    1 + 2 + ... + n = n × (n + 1) / 2

The trick is usually credited to **Carl Friedrich Gauss**. As the story goes,
his schoolteacher told the class to add up 1 to 100, expecting it to keep them
busy, and young Gauss had the answer (5050) almost immediately.

Here's why it works. Call the sum `x`, and write it twice, once forwards and
once backwards (using n = 4):

    x =  1 + 2 + 3 + 4
    x =  4 + 3 + 2 + 1

Add the two lines column by column:

    2x = 5 + 5 + 5 + 5

Every column adds to 5, which is `n + 1`. There are 4 columns, which is `n`.
So:

    2x = n × (n + 1)
     x = n × (n + 1) / 2

Check: 4 × 5 / 2 = 10, and 1 + 2 + 3 + 4 = 10. ✓

(Our range starts at 0, not 1, but adding 0 doesn't change the sum, so the
same formula works.)

## One C++ note

In C++, `int` can only hold numbers up to about 2.1 billion. If `n` were huge,
`n × (n + 1)` could overflow and give a wrong answer. LeetCode keeps `n` at
10,000 or less, so the biggest sum is around 50 million, which is safe.
Python doesn't have this problem: its integers grow as big as needed.

## Complexity

- **Time:** O(n) — one pass to subtract every number
- **Space:** O(1) — just one running total

## Solutions

- [Python](solution.py)
- [C++](solution.cpp)