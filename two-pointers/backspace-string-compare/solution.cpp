class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;

        while (true) {
            i = nextValid(s, i);
            j = nextValid(t, j);

            if (i < 0 && j < 0) {
                return true;           // both finished and everything matched
            }
            if (i < 0 || j < 0 || s[i] != t[j]) {
                return false;          // one ran out early, or letters differ
            }

            i--;
            j--;
        }
    }

private:
    // Walk left until we hit a letter that survives the backspaces.
    int nextValid(const string& text, int i) {
        int skip = 0;
        while (i >= 0) {
            if (text[i] == '#') {
                skip++;                // a backspace: one more letter to delete
            } else if (skip > 0) {
                skip--;                // this letter gets deleted
            } else {
                return i;              // this letter survives
            }
            i--;
        }
        return -1;                     // nothing left
    }
};

// Time: O(n + m), each character is visited a constant number of times
// Space: O(1), only a few integers