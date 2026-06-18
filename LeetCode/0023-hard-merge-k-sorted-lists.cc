class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;

        vector<ListNode*> full_list;
        for (auto& list : lists) {
            if (list == nullptr) continue;
            ListNode* node = list;
            while (node != nullptr) {
                full_list.push_back(node);
                node = node->next;
            }
        }
        if (full_list.size() == 0) return nullptr;
        std::sort(full_list.begin(), full_list.end(), [](ListNode* a, ListNode* b) {
            return a->val < b->val;
        });
        ListNode* head = full_list[0];
        ListNode* node = head;
        for (int i = 1; i < (int)full_list.size(); i++) {
            node->next = full_list[i];
            node = node->next;
        }
        node->next = nullptr;
        return head;
    }
};
