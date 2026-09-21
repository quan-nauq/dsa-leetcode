class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map each number we've seen to its index.
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // Check before inserting, so a number can't pair with itself.
            if (seen.contains(complement)) {
                return {seen[complement], i};
            }

            seen[nums[i]] = i;
        }

        // LeetCode guarantees exactly one answer, so this is never reached.
        return {};
    }
};

// Time: O(n) — one pass, hash map lookups are O(1) on average
// Space: O(n) — worst case almost every number goes into the map