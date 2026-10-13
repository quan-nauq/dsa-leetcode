class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow = head   # moves 1 step at a time
        fast = head   # moves 2 steps at a time

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

            # Same node (not just same value) means fast lapped slow: a cycle.
            if slow is fast:
                return True

        # fast fell off the end, so the list has an end: no cycle.
        return False

# Time: O(n)
# Space: O(1), two pointers