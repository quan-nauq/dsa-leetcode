class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;   // moves 1 step at a time
        ListNode* fast = head;   // moves 2 steps at a time

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            // Same address means fast lapped slow: a cycle.
            if (slow == fast) {
                return true;
            }
        }

        // fast fell off the end, so the list has an end: no cycle.
        return false;
    }
};

// Time: O(n)
// Space: O(1), two pointers