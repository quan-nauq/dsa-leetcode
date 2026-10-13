# Linked List Cycle

[LeetCode 141](https://leetcode.com/problems/linked-list-cycle/) · Easy · Linked List

## The problem

Given the head of a linked list, return `true` if the list has a cycle: some
node's `next` points back to an earlier node, so walking forward never ends.

## The simple way first

Walk the list and remember every node you've visited in a **set**. If you land
on a node already in the set, there's a cycle. If you reach the end, there isn't.

It works in O(n) time, but the set costs O(n) memory. Can we do it with no
extra memory?

## The idea

Use two pointers at different speeds, like two runners on a track:

- **slow** moves 1 node per step
- **fast** moves 2 nodes per step

**No cycle:** fast reaches the end of the list (`None`), so return `false`.

**Cycle:** both runners get stuck going around the loop. Fast is faster, so it
eventually catches up to slow from behind, and they land on the same node.
Same node means a cycle, so return `true`.

## Walkthrough

`3 → 2 → 0 → -4`, and `-4` points back to `2`.

| Step | slow | fast |
|------|------|------|
| start | 3 | 3 |
| 1 | 2 | 0 |
| 2 | 0 | 2 |
| 3 | -4 | -4 |

Both on node `-4`, so there's a cycle ✓

## Why fast can't skip over slow

Once both are inside the loop, fast gains exactly **1 node per step** on slow.
So the gap between them shrinks by 1 each step: 3, 2, 1, 0. It always passes
through 0, so they must land on the same node. Fast can never jump past slow,
because a gap of 1 becomes 0, not -1.

## Compare nodes, not values

The check is `slow is fast` (Python) or `slow == fast` on pointers (C++), which
compares **which node**, not what number is inside. Two different nodes can hold
the same value, so comparing `.val` would give wrong answers.

## Edge cases

- **Empty list:** `fast` is `None`, the loop never runs, returns `false`.
- **One node, no cycle:** `fast.next` is `None`, returns `false`.
- **One node pointing to itself:** slow and fast both move onto itself, they
  match, returns `true`.

## Complexity

- **Time:** O(n), fast either hits the end or catches slow within a few laps
- **Space:** O(1), just two pointers

## Solutions

- [Python](solution.py)
- [C++](solution.cpp)