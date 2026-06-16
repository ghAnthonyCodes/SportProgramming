class Solution {
public:
    bool hasCycle(ListNode* head) {
        while (head != nullptr) {
            if (head->val == -1e6) return true;
            head->val = -1e6;
            head = head->next;
        }
        return false;
    }
};
