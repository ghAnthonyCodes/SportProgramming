typedef vector<int> vi;
class Solution {
public:
    vi plusOne(vi& digits) {
        int N = (int)digits.size();
        int carry = 1;
        vi solution = digits;

        for (int n = N - 1; n >= 0; n--) {
            int sum = solution[n] + carry;
            solution[n] = sum % 10;
            carry = sum / 10;
        }

        if (carry > 0)
            solution.insert(solution.begin(), carry);
        return solution;
    }
};
