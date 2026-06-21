class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = dividend;
        long long b = divisor;
        return (int)max(min(a / b, 2147483647LL), -2147483648LL);
    }
};
