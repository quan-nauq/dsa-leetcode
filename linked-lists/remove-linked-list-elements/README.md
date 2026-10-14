# Remove Linked List Elements

[LeetCode 203](https://leetcode.com/problems/remove-linked-list-elements/) · Easy · Linked List

## The problem

Given the head of a linked list and a number `val`, remove every node whose
value equals `val`, and return the new head.

    1 → 2 → 6 → 3 → 6     remove 6     becomes     1 → 2 → 3

## The idea

To delete a node in a linked list, you don't touch the node itself. You make
the node **before** it skip over it:

    curr.next = curr.next.next

So we stand on the node *before* the one we're checking, and look at
`curr.next`:

- `curr.next` matches `val` → skip it: `curr.next = curr.next.next`
- Otherwise → it stays, so move forward: `curr = curr.next`

## The fake starting node

If the **head** must be removed, there's no node before it to rewire. To avoid
a special case, we put a fake node in front of the list. Now every real node,
including the head, has a node before it. At the end the real head is
`start.next`.

## Why we don't move after a removal

After skipping a node, the new `curr.next` is a node we haven't checked yet.
If we moved forward anyway, we'd jump past it.

`1 → 2 → 2 → 3`, remove 2:

| curr | curr.next | Action | List after |
|------|-----------|--------|------------|
| start | 1 | keep, move | 1 → 2 → 2 → 3 |
| 1 | 2 | remove, **stay** | 1 → 2 → 3 |
| 1 | 2 | remove, **stay** | 1 → 3 |
| 1 | 3 | keep, move | 1 → 3 |

If we had moved after the first removal, the second `2` would survive.

## Edge cases

- **Head matches:** the fake node handles it, no special code.
- **Every node matches:** all get skipped, the result is an empty list.
- **Empty list:** the loop never runs and `start.next` is `None`.

## Complexity

- **Time:** O(n), each node is checked once
- **Space:** O(1), no extra storage

## Solutions

- [Python](solution.py)
- [C++](solution.cpp)