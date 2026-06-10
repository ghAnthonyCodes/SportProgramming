class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> sol = vector<int>(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            int x = i;
            while (x > 0) {
                if (x & 1) sol[i]++;
                x >>= 1;
            }
        }
        return sol;
    }
};
