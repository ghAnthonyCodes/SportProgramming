class Solution {
public:
    int mySqrt(int x) {
        int lo = 0; int hi = 46341; long long m;
        for (int i=0; i<30; i++) {
            m = lo + (hi - lo) / 2;
            if (m * m <= x & (m + 1) * (m + 1) > x) return m;
            if (m * m > x) hi = m;
            else lo = m;
        }
        return -1;
    }
};
