class Solution:
    def sortedSquares(self, nums: list[int]) -> list[int]:
        n = len(nums)
        result = [0] * n

        # The biggest square is always at one of the two ends.
        front = 0
        back = n - 1

        # Fill the result from the last slot to the first.
        for pos in range(n - 1, -1, -1):
            if abs(nums[front]) >= abs(nums[back]):
                result[pos] = nums[front] * nums[front]
                front += 1
            else:
                result[pos] = nums[back] * nums[back]
                back -= 1

        return result

# Time: O(n), each number is looked at once
# Space: O(1) extra, the result list doesn't count