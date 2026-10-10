class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        // The biggest square is always at one of the two ends.
        int front = 0;
        int back = n - 1;

        // Fill the result from the last slot to the first.
        for (int pos = n - 1; pos >= 0; pos--) {
            if (abs(nums[front]) >= abs(nums[back])) {
                result[pos] = nums[front] * nums[front];
                front++;
            } else {
                result[pos] = nums[back] * nums[back];
                back--;
            }
        }

        return result;
    }
};

// Time: O(n), each number is looked at once
// Space: O(1) extra, the result vector doesn't count