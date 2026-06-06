class Solution {
public:
    string addBinary(string a, string b) {
        int sum = 0;
        int carry = 0;
        int a_ptr = (int)a.size() - 1;
        int b_ptr = (int)b.size() - 1;
        vector<int> answer = vector<int>();
        while (1) {
            sum = carry;
            if (a_ptr >= 0) sum += a[a_ptr--] - '0';
            if (b_ptr >= 0) sum += b[b_ptr--] - '0';
            if (sum <= 1) {
                carry = 0;
                answer.push_back(sum);
            } else if (sum == 2) {
                answer.push_back(0);
                carry = 1;
            } else {
                answer.push_back(1);
                carry = 1;
            }
            if (a_ptr == -1 && b_ptr == -1) break;
        }
        if (carry == 1)
            answer.push_back(1);
        ostringstream os;
        for (int i=answer.size() - 1; i>=0; i--)
            os << answer[i];
        return os.str();
    }
};
