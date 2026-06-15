class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr) return nullptr;
        if (head->next->next == nullptr) {
            head->next = nullptr;
            return head;
        }
        auto node = head;
        int size = 0;
        while (node != nullptr) {
            size++;
            node = node->next;
        }

        node = head;
        for (int i=0; i<size/2 - 1; i++) node = node->next;
        node->next = node->next->next;
        return head;
    }
};
