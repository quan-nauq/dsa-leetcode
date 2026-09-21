class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        # Map each number we've seen to its index.
        visited = {}

        for idx, num in enumerate(nums):
            complement = target - num

            # Check before inserting, so a number can't pair with itself.
            if complement in visited:
                return [visited[complement], idx]

            visited[num] = idx

        # LeetCode guarantees exactly one answer, so this is never reached.
        return []

# Time: O(n) — one pass, dictionary lookups are O(1) on average
# Space: O(n) — worst case almost every number goes into the dictionary