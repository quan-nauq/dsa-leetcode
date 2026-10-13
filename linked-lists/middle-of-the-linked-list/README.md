# Middle of the Linked List

[LeetCode 876](https://leetcode.com/problems/middle-of-the-linked-list/) · Easy · Linked List

## The problem

Given the head of a linked list, return the middle node. If there are two
middle nodes (even length), return the **second** one.

## The simple way first

A linked list doesn't know its own length, so:

1. Walk the whole list and count the nodes.
2. Walk again, this time `count // 2` steps.

It works and costs O(n) time, O(1) space. But it walks the list twice. Can we
do it in one pass?

## The idea

Use two pointers moving at different speeds:

- **slow** moves 1 node per step
- **fast** moves 2 nodes per step

Fast covers twice the distance. So when fast reaches the end, slow has covered
exactly half, which is the middle.

Keep going while fast has somewhere to jump: `fast` is a node and `fast.next`
is a node. When either is `None`, stop and return `slow`.

## Walkthrough

Odd length: `1 → 2 → 3 → 4 → 5`

| Step | slow | fast |
|------|------|------|
| start | 1 | 1 |
| 1 | 2 | 3 |
| 2 | 3 | 5 |

`fast.next` is `None`, so stop. Middle is **3** ✓

Even length: `1 → 2 → 3 → 4 → 5 → 6`

| Step | slow | fast |
|------|------|------|
| start | 1 | 1 |
| 1 | 2 | 3 |
| 2 | 3 | 5 |
| 3 | 4 | None |

`fast` fell off the end, so stop. Returns **4**, the second middle ✓

## Why it returns the second middle

For even length, fast goes past the last node (to `None`) instead of landing on
it, which gives slow one extra step. That one step is exactly the "second
middle" the problem asks for.

## Edge cases

- **One node:** `fast.next` is `None`, the loop never runs, returns that node.
- **Two nodes:** one step, slow lands on the second node, as required.

## Complexity

- **Time:** O(n), one pass (fast does n/2 steps)
- **Space:** O(1), two pointers

## Solutions

- [Python](solution.py)
- [C++](solution.cpp)