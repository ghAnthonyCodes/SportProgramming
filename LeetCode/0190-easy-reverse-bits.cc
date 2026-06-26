class Solution {
public:
    int reverseBits(int n) {
        int sol = 0;
        for (int i=0; i<32; i++) {
            sol = (sol << 1) + (n & 1);
            n >>= 1;
        }
        return sol;
    }
};
