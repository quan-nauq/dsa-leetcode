class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Sum of every number from 0 to n, if nothing were missing.
        int n = nums.size();
        int total = n * (n + 1) / 2;

        // Subtract what's actually there. Whatever's left is the missing one.
        for (int num : nums) {
            total -= num;
        }

        return total;
    }
};

// Time: O(n) — one pass
// Space: O(1) — just one running number