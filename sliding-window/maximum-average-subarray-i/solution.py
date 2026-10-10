class Solution:
    def findMaxAverage(self, nums: list[int], k: int) -> float:
        # Sum of the first window of size k.
        current = sum(nums[:k])
        best = current

        # Slide the window right: add the new number, drop the old one.
        for j in range(k, len(nums)):
            current += nums[j] - nums[j - k]
            best = max(best, current)

        # Compare sums while sliding, divide once at the end.
        return best / k

# Time: O(n), each number enters and leaves the window once
# Space: O(1)