class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        # Next spot where a non-zero number should go.
        write = 0

        # Copy every non-zero number to the front, in the order we meet them.
        for num in nums:
            if num != 0:
                nums[write] = num
                write += 1

        # Everything from `write` onward is leftover, so fill it with zeros.
        for i in range(write, len(nums)):
            nums[i] = 0

# Time: O(n), two passes
# Space: O(1), changes the array in place