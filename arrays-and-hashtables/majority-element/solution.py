class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        # Start by guessing the first number is the majority.
        candidate = nums[0]
        count = 1

        for i in range(1, len(nums)):
            # Same as the candidate: a vote for it. Different: a vote against.
            if nums[i] == candidate:
                count += 1
            else:
                count -= 1

            # Votes cancelled out completely, so switch to the current number.
            if count == 0:
                candidate = nums[i]
                count = 1

        # The problem guarantees a majority exists, so the survivor is it.
        return candidate

# Time: O(n) — one pass
# Space: O(1) — just a candidate and a count