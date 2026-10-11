class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i = 0  # position in s: the next letter we still need to find
        j = 0  # position in t: where we're currently looking

        while i < len(s) and j < len(t):
            if s[i] == t[j]:
                i += 1   # found it, now look for the next letter of s
            j += 1       # always move forward in t

        # If i reached the end, every letter of s was found in order.
        return i == len(s)

# Time: O(m), one pass through t
# Space: O(1)