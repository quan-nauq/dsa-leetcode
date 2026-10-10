# Maximum Average Subarray I

[LeetCode 643](https://leetcode.com/problems/maximum-average-subarray-i/) · Easy · Sliding Window

## The problem

Given a list of numbers and a window size `k`, find the group of `k`
consecutive numbers with the highest average, and return that average.

## The simple way first

For every possible window, add up its `k` numbers and compare. It works, but
each window re-adds `k` numbers, so it costs O(n × k) and can time out on big
inputs.

## The idea

Every window has the same size `k`, so **comparing averages is the same as
comparing sums**. We can skip dividing until the very end.

Now look at two neighbouring windows:

    [1, 12, -5, -6] 50, 3        sum = 2
     1 [12, -5, -6, 50] 3        sum = 51

They share `k - 1` numbers. Only the ends changed: `1` left, `50` came in.
So instead of re-adding everything, **slide**:

    new sum = old sum + (number entering) − (number leaving)

1. Add up the first window once.
2. Slide right one step at a time, updating the sum with one add and one subtract.
3. Keep track of the biggest sum seen.
4. Divide the biggest sum by `k` at the end.

## Walkthrough

`nums = [1, 12, -5, -6, 50, 3]`, `k = 4`

| Window | Entering | Leaving | Sum | Best so far |
|--------|----------|---------|-----|-------------|
| 1, 12, -5, -6 | start | start | 2 | 2 |
| 12, -5, -6, 50 | 50 | 1 | 51 | 51 |
| -5, -6, 50, 3 | 3 | 12 | 42 | 51 |

Best sum is 51, so the answer is 51 / 4 = **12.75** ✓

## A bug worth remembering

A first attempt added each window into one running total **without resetting
it**, so every window's sum piled on top of the last one and the answer came
out wrong (23.75 instead of 12.75). Sliding avoids this: the total is always
exactly the current window, because we remove what leaves.

## Complexity

- **Time:** O(n), each number enters and leaves the window once
- **Space:** O(1), a running sum and a best sum

## Solutions

- [Python](solution.py)
- [C++](solution.cpp)