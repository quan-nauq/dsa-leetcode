class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;   // the already-reversed part, starts empty
        ListNode* curr = head;      // the node we're about to flip

        while (curr != nullptr) {
            ListNode* next = curr->next;   // save the rest before we cut it off
            curr->next = prev;             // flip this node's arrow backwards
            prev = curr;                   // the reversed part now starts at curr
            curr = next;                   // move on to the saved rest
        }

        // When curr falls off the end, prev is the old last node = new head.
        return prev;
    }
};

// Time: O(n), each node is visited once
// Space: O(1), just a few pointers