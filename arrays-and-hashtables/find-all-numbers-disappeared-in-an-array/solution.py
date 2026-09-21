class Solution:
    def findDisappearedNumbers(self, nums: list[int]) -> list[int]:
        # Each value v "owns" position v - 1. Mark it by making it negative.
        for num in nums:
            idx = abs(num) - 1          # num may already be negative from an earlier mark
            nums[idx] = -abs(nums[idx]) # -abs keeps it negative if already marked

        # Any position still positive was never marked, so idx + 1 never appeared.
        return [idx + 1 for idx, val in enumerate(nums) if val > 0]

# Time: O(n) — two passes
# Space: O(1) extra — marks are stored in the input array itself