class Solution {
public:
    int hammingWeight(int n) {
        int sol = 0;
        while (n > 0) {
            sol += n & 1;
            n >>= 1;
        }
        return sol;
    }
};
