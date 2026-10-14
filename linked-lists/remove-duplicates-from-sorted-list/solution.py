class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = head

        while curr and curr.next:
            if curr.val == curr.next.val:
                curr.next = curr.next.next   # duplicate: skip it, stay in place
            else:
                curr = curr.next             # different: move on

        return head

# Time: O(n), each node is checked once
# Space: O(1)