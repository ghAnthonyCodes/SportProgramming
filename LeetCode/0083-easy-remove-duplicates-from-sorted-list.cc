class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* curr = head;
        while (true) {
            while (curr->next != nullptr && curr->val == curr->next->val)
                curr->next = curr->next->next;
            if (curr->next == nullptr) break;
            curr = curr->next;
        }
        return head;
    }
};
