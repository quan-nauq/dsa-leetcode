class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        # Track numbers we've already seen; a repeat means a duplicate.
        visited = set()

        for num in nums:
            if num in visited:
                return True
            visited.add(num)

        # Only reachable if the loop finished without finding a repeat.
        return False

# Time: O(n) — one pass, set lookups are O(1) on average
# Space: O(n) — worst case every number goes into the set