# Palindrome Linked List

[LeetCode 234](https://leetcode.com/problems/palindrome-linked-list/) · Easy · Linked List

## The problem

Given the head of a linked list, return `true` if it reads the same forwards
and backwards.

    1 → 2 → 2 → 1     true
    1 → 2             false

## The simple way first

Copy all the values into an array and check whether the array equals its own
reverse. It's short and easy, but the array costs O(n) extra memory.

## The idea

A linked list only goes forward, so we can't walk it from the back. Instead we
**flip the second half** so it can be read backwards, then compare the halves.

1. **Find the middle** with slow and fast pointers, as in
   [Middle of the Linked List](../middle-of-the-linked-list/).
2. **Reverse the second half**, as in [Reverse Linked List](../reverse-linked-list/).
3. **Compare** the first half with the reversed second half, node by node. Any
   mismatch means it's not a palindrome.

## Walkthrough

`1 → 2 → 2 → 1`

| Step | What happens |
|------|--------------|
| find middle | slow stops on the second `2` |
| reverse second half | the back half `2 → 1` becomes `1 → 2` |
| compare | `1 == 1`, then `2 == 2`, then `right` runs out → `true` |

## Why we stop when `right` runs out

The two pointers don't always meet, so we can't stop on `left == right`.

| List | left visits | right visits |
|------|-------------|--------------|
| `1 → 2 → 2 → 1` (even) | index 0, 1 | index 3, 2 |
| `1 → 2 → 3 → 2 → 1` (odd) | index 0, 1, 2 | index 4, 3, 2 |

In the even case they never land on the same node, so a "stop when they meet"
check would run forever. Stopping when `right` hits `None` works for both.

In the odd case, the last comparison puts both pointers on the middle `3`,
comparing it with itself. That's harmless.

## Trade-off

This changes the list: the back half stays reversed afterwards. That's the
price of O(1) space. In real code you'd reverse it back before returning.

## Edge cases

- **One node:** it's a palindrome. It compares with itself and returns `true`.
- **Two equal nodes (`1 → 1`):** slow stops on the second, which matches the
  head, so it returns `true`.

## Complexity

- **Time:** O(n), find the middle, reverse, compare
- **Space:** O(1), nodes are re-linked in place

## Solutions

- [Python](solution.py)
- [C++](solution.cpp)