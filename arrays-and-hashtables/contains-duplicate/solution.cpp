class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Track numbers we've already seen; a repeat means a duplicate.
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.contains(num)) {
                return true;
            }
            seen.insert(num);
        }

        // Only reachable if the loop finished without finding a repeat.
        return false;
    }
};

// Time: O(n) — one pass, hash set lookups are O(1) on average
// Space: O(n) — worst case every number goes into the set