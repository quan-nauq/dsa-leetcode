class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 1. Find the middle: slow ends up at the start of the second half.
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse the second half.
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 3. Compare the first half with the reversed second half.
        ListNode* left = head;
        ListNode* right = prev;
        while (right != nullptr) {   // stop when the reversed half runs out
            if (left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }

        return true;
    }
};

// Time: O(n)
// Space: O(1)