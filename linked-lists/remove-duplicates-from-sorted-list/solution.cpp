class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                curr->next = curr->next->next;   // duplicate: skip it, stay in place
            } else {
                curr = curr->next;               // different: move on
            }
        }

        return head;
    }
};

// Time: O(n), each node is checked once
// Space: O(1)