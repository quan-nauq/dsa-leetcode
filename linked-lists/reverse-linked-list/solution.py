class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None      # the already-reversed part, starts empty
        curr = head      # the node we're about to flip

        while curr:
            nxt = curr.next    # save the rest of the list before we cut it off
            curr.next = prev   # flip this node's arrow backwards
            prev = curr        # the reversed part now starts at curr
            curr = nxt         # move on to the saved rest

        # When curr falls off the end, prev is the old last node = new head.
        return prev

# Time: O(n), each node is visited once
# Space: O(1), just a few pointers