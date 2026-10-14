class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode start(0);           // fake starting node, never returned
        ListNode* tail = &start;     // where the next node gets attached

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;     // move list1 forward
            } else {
                tail->next = list2;
                list2 = list2->next;     // move list2 forward
            }
            tail = tail->next;
        }

        // One list ran out, so attach whatever is left of the other.
        tail->next = (list1 != nullptr) ? list1 : list2;

        return start.next;
    }
};

// Time: O(n + m), each node is visited once
// Space: O(1), nodes are re-linked, not copied