class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (letters[mid] > target) {
                right = mid - 1;    // mid is bigger, but maybe an earlier one is too
            } else {
                left = mid + 1;     // mid is too small (or equal), look right
            }
        }

        // left is now the first letter bigger than target.
        // If it ran off the end, wrap around to the start.
        return letters[left % n];
    }
};

// Time: O(log n)
// Space: O(1)