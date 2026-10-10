class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def next_valid(text: str, i: int) -> int:
            # Walk left until we hit a letter that survives the backspaces.
            skip = 0
            while i >= 0:
                if text[i] == "#":
                    skip += 1          # a backspace: one more letter to delete
                elif skip > 0:
                    skip -= 1          # this letter gets deleted
                else:
                    return i           # this letter survives
                i -= 1
            return -1                  # nothing left

        i = len(s) - 1
        j = len(t) - 1

        while True:
            i = next_valid(s, i)
            j = next_valid(t, j)

            if i < 0 and j < 0:
                return True            # both finished and everything matched
            if i < 0 or j < 0 or s[i] != t[j]:
                return False           # one ran out early, or letters differ

            i -= 1
            j -= 1

# Time: O(n + m), each character is visited a constant number of times
# Space: O(1), only a few integers