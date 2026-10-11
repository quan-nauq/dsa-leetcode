class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;  // position in s: the next letter we still need to find
        int j = 0;  // position in t: where we're currently looking

        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;   // found it, now look for the next letter of s
            }
            j++;       // always move forward in t
        }

        // If i reached the end, every letter of s was found in order.
        return i == s.size();
    }
};

// Time: O(m), one pass through t
// Space: O(1)