class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Next spot where a non-zero number should go.
        int write = 0;

        // Copy every non-zero number to the front, in the order we meet them.
        for (int num : nums) {
            if (num != 0) {
                nums[write] = num;
                write++;
            }
        }

        // Everything from `write` onward is leftover, so fill it with zeros.
        for (int i = write; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

// Time: O(n), two passes
// Space: O(1), changes the array in place