typedef vector<int> vi;
typedef unordered_map<long long, long long> mii;

class Solution {
public:
    int maximumLength(vi& nums) {
        mii M;
        for (auto& n : nums) M[n]++;
        int local_sol = 0;
        int sol = 0;
        for (const auto& [k, v] : M) {
            if (k == 1) {
                sol = max(v & 1 ? (int)v : (int)v - 1, sol);
                continue;
            }
            local_sol = 1;
            long long p = k;
            while (1) {
                if (M[p] < 2) {
                    sol = max(sol, 2 * local_sol - 1);
                    break;
                }
                // We can extend possibly
                p = p * p;
                if (M.find(p) == M.end()) {
                    sol = max(sol, 2 * local_sol - 1);
                    break;
                }
                local_sol++;
            }
        }
        return sol;
    }
};
