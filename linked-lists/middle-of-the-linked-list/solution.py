class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = head   # moves 1 step at a time
        fast = head   # moves 2 steps at a time

        # When fast reaches the end, slow has covered half the distance.
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        return slow

# Time: O(n), one pass
# Space: O(1), two pointers