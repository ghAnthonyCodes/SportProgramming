class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> yo;
        while (1) {
            if (head == nullptr) break;
            yo.push_back(head->val);
            head = head->next;
        }
        int sol = 0;
        for (int i=0; i<yo.size()/2; i++)
            sol = max(sol, yo[i] + yo[(int)yo.size()-i-1]);
        return sol;
    }
};
