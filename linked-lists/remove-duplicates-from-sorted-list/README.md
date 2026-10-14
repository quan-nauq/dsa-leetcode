# Remove Duplicates from Sorted List

[LeetCode 83](https://leetcode.com/problems/remove-duplicates-from-sorted-list/) · Easy · Linked List

## The problem

Given the head of a **sorted** linked list, delete duplicates so each value
appears only once, and return the list.

    1 → 1 → 2 → 3 → 3     becomes     1 → 2 → 3

## The idea

Because the list is sorted, equal values are always **neighbours**. So we never
need a set or a second pass. We just compare each node with the next one:

- Same value → skip the next node: `curr.next = curr.next.next`
- Different value → move forward: `curr = curr.next`

## Why we don't move after a removal

After skipping a node, the new `curr.next` might be yet another copy. We stay
put and compare again.

`1 → 1 → 1 → 2`:

| curr | curr.next | Action | List after |
|------|-----------|--------|------------|
| 1 | 1 | duplicate, **stay** | 1 → 1 → 2 |
| 1 | 1 | duplicate, **stay** | 1 → 2 |
| 1 | 2 | different, move | 1 → 2 |

Same rule as [Remove Linked List Elements](../remove-linked-list-elements/).

## Why no fake starting node

There, the head could be deleted, so we needed a node in front of it. Here, we
always keep the **first** copy of each value, so the head is never removed.

## Edge cases

- **Empty list:** `curr` is `None`, the loop never runs, returns `None`.
- **One node:** `curr.next` is `None`, the loop never runs, returns it.
- **All the same value:** everything after the head gets skipped, leaving one node.

## Complexity

- **Time:** O(n), each node is checked once
- **Space:** O(1)

## Solutions

- [Python](solution.py)
- [C++](solution.cpp)