class Solution {
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* sol = nullptr;
        ListNode* node = headA;
        while (node != nullptr) {
            node->val *= -1;
            node = node->next;
        }
        while (headB != nullptr) {
            if (headB->val < 0) {
                sol = headB;
                break;
            };
            headB = headB->next;
        }
        node = headA;
        while (node != nullptr) {
            node->val *= -1;
            node = node->next;
        }
        return sol;
    }
};
