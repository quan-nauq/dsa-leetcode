# Backspace String Compare

[LeetCode 844](https://leetcode.com/problems/backspace-string-compare/) · Easy · Two Pointers

## The problem

You get two strings. A `#` means "backspace": it deletes the letter before it
(and does nothing if there is no letter). Type both strings into an empty text
editor and return `true` if they end up identical.

## The simple way first

Use a **stack**. Go through the string: a letter gets pushed, a `#` pops the
last letter. Do it for both strings and compare the results.

It's short and easy to get right, but the stack costs O(n) extra memory. The
follow-up asks: can we do it in O(1) space?

## The idea

To skip the stack, we can't build the final strings. We have to compare them
directly. The catch: going **left to right**, we can't tell if a letter
survives, because a `#` further along might delete it.

So we go **right to left**. Now a `#` shows up *before* the letters it deletes,
and we can count them:

- See a `#` → add 1 to a **skip** counter (one more letter to delete).
- See a letter while skip > 0 → this letter is deleted, subtract 1 from skip.
- See a letter while skip = 0 → this letter survives.

We do this with two pointers, one at the end of each string:

1. Move each pointer left until it lands on a surviving letter.
2. Compare those two letters. Different → return `false`.
3. Move both pointers one step left and repeat.
4. Both pointers run out at the same time → every letter matched → `true`.
   Only one runs out → the strings have different lengths → `false`.

## Walkthrough

`s = "ab#c"`, `t = "ad#c"`. Both type out as `"ac"`.

| Step | Pointer in s | Pointer in t | What happens |
|------|--------------|--------------|--------------|
| 1 | `c` (index 3) | `c` (index 3) | letters survive, `c == c` ✓ |
| 2 | `#`, skip 1, `b` deleted, lands on `a` (index 0) | `#`, skip 1, `d` deleted, lands on `a` (index 0) | `a == a` ✓ |
| 3 | nothing left | nothing left | both finished → `true` |

## Why go backwards

Going forward, every letter is "maybe deleted later", so you'd have to store
them and wait. Going backward, every `#` tells you about the letters still to
come, so you can decide on the spot and store nothing.

## Edge cases

- **Extra backspaces:** `"a##c"` becomes `"c"`. Skip just stays positive and
  nothing breaks, because there's no letter left to delete.
- **Everything deleted:** `"ab##"` becomes `""`. The pointer runs out and
  returns -1, which matches another empty result.
- **Different lengths:** one pointer finishes while the other still has a
  letter, so we return `false`.

## Stack or two pointers?

| | Stack | Two pointers |
|---|---|---|
| Code | short | longer, trickier |
| Space | O(n) | O(1) |
| Good for | a first answer | the follow-up |

## Complexity

- **Time:** O(n + m), each character is visited a constant number of times
- **Space:** O(1), just two pointers and a skip counter

## Solutions

- [Python](solution.py)
- [C++](solution.cpp)