/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0)
            return head;
        std::vector<int> nl = { };
        ListNode *n = head;
        while (n != nullptr) {
            nl.push_back(n->val);
            n = n->next;
        }
        n = head;

        int s = nl.size();
        int ptr = ((-k % s) + s) % s;
        for (int x=ptr; x<nl.size(); x++) {
            n->val = nl[x];
            n = n->next;
        }
        for (int x=0; x<ptr; x++) {
            n->val = nl[x];
            n = n->next;
        }
        return head;
    }
};
