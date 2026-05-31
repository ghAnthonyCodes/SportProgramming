class Solution {
public:
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        ListNode* s = nullptr;
        ListNode* answer = nullptr;
        int carry = 0;
        int sum = 0;
        int a_val = 0;
        int b_val = 0;
        while (a != nullptr || b != nullptr) {
            
            if (a != nullptr) {
                a_val = a->val;
                a = a->next;
            } else a_val = 0;

            if (b != nullptr) {
                b_val = b->val;
                b = b->next;
            } else b_val = 0;

            // Carry out the carry out
            sum = a_val + b_val + carry;
            carry = sum / 10;
            
            // Update answer logic
            if (s == nullptr) {
                s = new ListNode(sum % 10);
                answer = s;
            } else {
                s->next = new ListNode(sum % 10);
                s = s->next;
            }
        }

        while (carry > 0) {
            s->next = new ListNode(carry % 10);
            carry /= 10;
        }
           
        return answer;
    }
};
