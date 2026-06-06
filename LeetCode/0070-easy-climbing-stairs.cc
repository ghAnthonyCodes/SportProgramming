class Solution {
public:
    int climbStairs(int n) {
        vector<int> D = vector<int>(46, 0);
        D[0] = 1;
        D[1] = 1;
        D[2] = 2;
        for (int i=3; i <= 45; i++) D[i] = D[i - 1] + D[i - 2];
        return D[n];
    }
};
