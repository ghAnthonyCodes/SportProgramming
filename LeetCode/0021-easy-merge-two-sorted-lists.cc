class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr_node = nullptr;
        ListNode* answer = curr_node;
        while (1) {
            if (list1 == nullptr && list2 == nullptr) break;

            int next_val;
            if (list1 != nullptr && list2 != nullptr) {
                if (list1->val < list2->val) {
                    next_val = list1->val;
                    list1 = list1->next;
                } else {
                    next_val = list2->val;
                    list2 = list2->next;
                }
            } else if (list1 != nullptr) {
                next_val = list1->val;
                list1 = list1->next;
            } else {
                next_val = list2->val;
                list2 = list2->next;
            }
            if (curr_node == nullptr) {
                curr_node = new ListNode(next_val);
                answer = curr_node;
            } else {
                curr_node->next = new ListNode(next_val);
                curr_node = curr_node->next;
            }
        }
        return answer;
    }
};
