class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode start(0);           // fake starting node, so removing the head is not special
        ListNode* curr = &start;
        start.next = head;

        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                curr->next = curr->next->next;   // remove it, stay in place
            } else {
                curr = curr->next;               // keep it, move on
            }
        }

        return start.next;
    }
};

// Time: O(n), each node is checked once
// Space: O(1)