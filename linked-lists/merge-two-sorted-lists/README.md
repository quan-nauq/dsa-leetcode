# Merge Two Sorted Lists

[LeetCode 21](https://leetcode.com/problems/merge-two-sorted-lists/) · Easy · Linked List

## The problem

You get two linked lists, each sorted from smallest to biggest. Merge them into
one sorted list and return its head. The new list must be built by splicing
together the existing nodes.

    1 → 2 → 4     and     1 → 3 → 4     becomes     1 → 1 → 2 → 3 → 4 → 4

## The idea

Think of two sorted queues merging into one line. Look at the front person of
each queue, and let the smaller one go first.

We keep two "fingers", one at the front of each list, plus a **tail** that
marks the end of the merged list so far. Each round:

1. Compare the two front nodes.
2. Attach the smaller one to `tail.next`.
3. Move that list's finger forward, and move `tail` onto the node we just attached.

When one list runs out, the other is already sorted, so attach the whole
leftover in one step.

## The fake starting node

The merged list needs a head, but we don't know yet which node comes first. To
avoid special-casing the first attachment, we start with a **fake node** and
attach everything after it. At the end, the real head is `start.next`.

Without it, the first round would need its own `if` just to decide the head.

## Walkthrough

`list1 = 1 → 3`, `list2 = 2 → 4`

| list1 | list2 | Smaller | Merged so far |
|-------|-------|---------|---------------|
| 1 | 2 | 1 (list1) | 1 |
| 3 | 2 | 2 (list2) | 1 → 2 |
| 3 | 4 | 3 (list1) | 1 → 2 → 3 |
| None | 4 | list1 ran out | attach leftover: 1 → 2 → 3 → 4 |

## Moving a finger vs rewiring a node

Two different actions that look alike:

- `list1 = list1.next` **moves your finger** along the list. Nothing changes.
- `list1.next = something` **rewires** the list. It changes where a node points.

In this problem the only rewiring is `tail.next = ...`. Writing
`list1.next = list1` by mistake makes a node point at itself, which creates an
endless loop.

## Edge cases

- **Both empty:** the loop never runs, both are `None`, returns `None`.
- **One empty:** the loop never runs, the leftover line attaches the other list.
- **Equal values:** `<=` takes from `list1` first, which is fine either way.

## Complexity

- **Time:** O(n + m), every node is attached once
- **Space:** O(1), nodes are re-linked rather than copied

## Solutions

- [Python](solution.py)
- [C++](solution.cpp)