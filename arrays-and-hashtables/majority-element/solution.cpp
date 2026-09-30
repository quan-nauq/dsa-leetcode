class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Start by guessing the first number is the majority.
        int candidate = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); i++) {
            // Same as the candidate: a vote for it. Different: a vote against.
            if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }

            // Votes cancelled out completely, so switch to the current number.
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            }
        }

        // The problem guarantees a majority exists, so the survivor is it.
        return candidate;
    }
};

// Time: O(n) — one pass
// Space: O(1) — just a candidate and a count