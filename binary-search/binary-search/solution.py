class Solution:
    def search(self, nums: list[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = left + (right - left) // 2

            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1     # target is to the right, drop the left half
            else:
                right = mid - 1    # target is to the left, drop the right half

        # The search area is empty, so the target isn't in the list.
        return -1

# Time: O(log n), the search area halves every step
# Space: O(1)