class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // Each value v "owns" position v - 1. Mark it by making it negative.
        for (int num : nums) {
            int idx = abs(num) - 1;          // num may already be negative from an earlier mark
            nums[idx] = -abs(nums[idx]);     // -abs keeps it negative if already marked
        }

        // Any position still positive was never marked, so idx + 1 never appeared.
        vector<int> result;
        for (int idx = 0; idx < nums.size(); idx++) {
            if (nums[idx] > 0) {
                result.push_back(idx + 1);
            }
        }
        return result;
    }
};

// Time: O(n) — two passes
// Space: O(1) extra — marks are stored in the input array itself