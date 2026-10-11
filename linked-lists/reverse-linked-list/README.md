# Reverse Linked List

[LeetCode 206](https://leetcode.com/problems/reverse-linked-list/) · Easy · Linked List

## The problem

Given the head of a linked list, reverse it and return the new head.

    1 → 2 → 3 → None     becomes     3 → 2 → 1 → None

## The idea

Each node only knows about the node **after** it. To reverse the list, make
every node point at the node **before** it instead.

Walk through the list once, flipping one arrow at a time. We need two
pointers:

- **curr**: the node we're flipping right now
- **prev**: the node before it (starts as `None`, because the new last node
  must point at nothing)

For each node:

1. **Save** `curr.next` in a variable. If we skip this, flipping the arrow
   cuts off the rest of the list and we can never reach it again.
2. **Flip**: `curr.next = prev`.
3. **Step forward**: `prev` becomes `curr`, `curr` becomes the saved node.

When `curr` falls off the end (`None`), `prev` is sitting on the old last node,
which is the new head.

## Walkthrough

`1 → 2 → 3`

| curr | saved next | flip | prev after | Reversed part so far |
|------|------------|------|------------|----------------------|
| 1    | 2          | 1 → None | 1      | 1 → None             |
| 2    | 3          | 2 → 1    | 2      | 2 → 1 → None         |
| 3    | None       | 3 → 2    | 3      | 3 → 2 → 1 → None     |

`curr` is now `None`, so return `prev`, which is node 3 ✓

## Why save `next` first

A node holds the only link to the rest of the list. Overwrite `curr.next` before
saving it and the remaining nodes become unreachable, so the list is lost.

## Edge cases

- **Empty list:** `curr` starts as `None`, the loop never runs, and `prev` is
  `None`. Returns an empty list.
- **One node:** its arrow flips to `None` (it already was), and the node
  returns itself.

## Recursive version

You can also solve it with recursion: reverse everything after the head, then
make the second node point back at the head. It's shorter to write but uses
O(n) space for the call stack, so the loop is the better default.

## Complexity

- **Time:** O(n), each node is visited once
- **Space:** O(1), just three pointers

## Solutions

- [Python](solution.py)
- [C++](solution.cpp)