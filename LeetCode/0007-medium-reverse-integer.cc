class Solution {
public:
    int reverse(int x_in) {
        int max_int = 2147483647;
        int min_int = -2147483648;
        //                2147483645
        long x = x_in;
        long mult = 1;
        long sol = 0;
        bool is_neg = x < 0;
        if (is_neg) x *= -1;
        while (x > 0) {            
            sol = sol * 10 + (x % 10);
            x /= 10;
        }

        sol = is_neg ? -1 * sol : sol;
        return (sol < min_int || sol > max_int) ? 0 : sol;
    }
};
