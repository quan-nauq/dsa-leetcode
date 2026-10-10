class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Sum of the first window of size k.
        double current = 0;
        for (int x = 0; x < k; x++) {
            current += nums[x];
        }
        double best = current;

        // Slide the window right: add the new number, drop the old one.
        for (int j = k; j < nums.size(); j++) {
            current += nums[j] - nums[j - k];
            best = max(best, current);
        }

        // Compare sums while sliding, divide once at the end.
        return best / k;
    }
};

// Time: O(n), each number enters and leaves the window once
// Space: O(1)