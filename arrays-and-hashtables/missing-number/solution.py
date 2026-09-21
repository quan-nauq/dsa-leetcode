class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        # Sum of every number from 0 to n, if nothing were missing.
        n = len(nums)
        total = n * (n + 1) // 2

        # Subtract what's actually there. Whatever's left is the missing one.
        for num in nums:
            total -= num

        return total

# Time: O(n) — one pass
# Space: O(1) — just one running number