class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        start = ListNode(0, head)   # fake starting node, so removing the head is not special
        curr = start

        while curr.next:
            if curr.next.val == val:
                curr.next = curr.next.next   # remove it, stay in place
            else:
                curr = curr.next             # keep it, move on

        return start.next

# Time: O(n), each node is checked once
# Space: O(1)