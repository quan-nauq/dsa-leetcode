class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        # 1. Find the middle: slow ends up at the start of the second half.
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # 2. Reverse the second half.
        prev = None
        curr = slow
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt

        # 3. Compare the first half with the reversed second half.
        left = head
        right = prev
        while right:   # stop when the reversed half runs out
            if left.val != right.val:
                return False
            left = left.next
            right = right.next

        return True

# Time: O(n)
# Space: O(1)