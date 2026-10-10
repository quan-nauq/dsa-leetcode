# Squares of a Sorted Array

[LeetCode 977](https://leetcode.com/problems/squares-of-a-sorted-array/) · Easy · Two Pointers

## The problem

Given a list of numbers sorted from smallest to biggest (it can include
negatives), return a list of each number **squared**, also sorted from smallest
to biggest.

## The simple way first

Square every number, then sort the result. It works, but sorting costs
O(n log n). We can do better, because the input is already sorted.

## The idea

Squaring makes negatives positive, so the order gets scrambled:

    [-4, -1, 0, 3, 10]  →  [16, 1, 0, 9, 100]

But look at where the big squares come from. The input is sorted, so the
numbers **farthest from zero** are at the two ends: the most negative on the
left, the most positive on the right. The numbers closest to zero are in the
middle, and they have the smallest squares.

So the biggest square is always at **one of the two ends**. That gives us a plan:

1. Put one pointer at the left end and one at the right end.
2. Compare the two ends (ignoring the minus sign, using `abs`).
3. The bigger one has the biggest square. Place that square in the **last open
   slot** of the result, then move that pointer inward.
4. Repeat. The next biggest square goes in the second-to-last slot, and so on.

We build the answer from the back to the front, so it comes out sorted without
any sorting step.

## Walkthrough

`nums = [-4, -1, 0, 3, 10]`

| slot | front → back values | bigger end | square placed | pointer moves |
|------|---------------------|------------|---------------|---------------|
| 4    | -4 vs 10            | 10 (back)  | 100           | back moves in |
| 3    | -4 vs 3             | -4 (front) | 16            | front moves in |
| 2    | -1 vs 3             | 3 (back)   | 9             | back moves in |
| 1    | -1 vs 0             | -1 (front) | 1             | front moves in |
| 0    | 0 vs 0              | 0 (front)  | 0             | front moves in |

Result: `[0, 1, 9, 16, 100]` ✓

## Why we fill from the back

If we filled from the front, we'd need the *smallest* square first, and the
smallest is hiding somewhere in the middle, so we'd have to search for it.
The *biggest* square is always sitting at an end, so we can always find it
instantly. That's why we start with the biggest and work backwards.

## Why not write into the input array

It's tempting to save space by writing the squares back into `nums`. Don't:
you'd overwrite numbers the pointers haven't read yet, and later steps would
square a number that's already been squared. The answer gets its own list.

## Complexity

- **Time:** O(n), each number is placed once
- **Space:** O(1) extra, the result list is the answer and doesn't count

## Solutions

- [Python](solution.py)
- [C++](solution.cpp)