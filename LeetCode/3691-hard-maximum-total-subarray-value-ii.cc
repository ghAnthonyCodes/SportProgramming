#include <queue>

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef map<int, map<int, bool>> mmib;

/*
    [18, 36, 6] -> [(6, 2), (18, 0), (36, 1)]
    min_idx = 1, max_idx = 2
    V[0][2] = 1, sol = 30
    v[1][2] = 1, sol = 60

    // Next iteration
    V[1][2] ?, yes, need to pick new [lp, rp]

    O               M
    [20, 21, 46] -> [(20, 0), (21, 1), (46, 2)]
    The problem comes down to finding the proper search order
    in terms of modified, it will be
    0, 2: 26
    1, 2: 25
    0, 1: 1


*/

class Solution {
public:
    ll maxTotalValue(vi& nums, int k) {
        int N = (int)nums.size();
        if (N == 1) return 0;
        
        ll max_subarrays = (ll)N * ((ll)N - 1LL) / 2LL;
        ll practical_k = min((ll)k, max_subarrays);
        vector<map<int, bool>> V_subarray = vector<map<int, bool>>(N);
        vector<map<int, bool>> V_bfs = vector<map<int, bool>>(N);
        vpii D = vpii(N);
        for (int n = 0; n < N; n++) D[n] = { nums[n], n };
        sort(D.begin(), D.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first) return a.first < 5 ? a.second > b.second : a.second < b.second;
            return a.first < b.first;
        });

        auto Q = priority_queue<pair<int, pair<int, int>>>();
        Q.push({ D[N - 1].first - D[0].first, { 0, N - 1 } });
        V_bfs[0][N - 1] = 1;
        ll solution = 0;

        // int pops = 0;

        while (!Q.empty()) {

            auto top = Q.top(); Q.pop();
            int lp = top.second.first;
            int rp = top.second.second;

            // pops++;
            // printf("Pops: %d, Fringe Size: %d\n", pops, Q.size());

            // printf("Evaluating D[%d], D[%d] - K: %lld\n", lp, rp, practical_k);
            auto [min_idx, max_idx] = std::minmax(D[lp].second, D[rp].second);

            if (!V_subarray[min_idx][max_idx]) {
                ll additional = D[rp].first - D[lp].first;
                for (int i = 0; i <= min_idx; i++) {
                    for (int j = max_idx; j < N; j++) {
                        if (!V_subarray[i][j]) {
                            V_subarray[i][j] = 1;
                            practical_k--;
                            solution += additional;
                            if (practical_k == 0) return solution;
                        } else break;
                    }
                }
            }

            // Add neighbors that aren't already in it
            int next_lp = lp + 1;
            int next_rp = rp - 1;
            if (next_lp < N && !V_bfs[next_lp][rp] && next_lp < rp) {
                // int base_left = lp + 1;
                // int base_val = D[lp + 1].first;
                // while (base_left + 1 < rp && D[base_left + 1].first == base_val && !V_subarray[D[base_left + 1].second][rp]) // base_left++;
                // printf("    Adding neighbor: %d %d\n", lp + 1, rp);
                Q.push({ D[rp].first - D[next_lp].first, { next_lp, rp } });
                V_bfs[next_lp][rp] = true;
            }
            if (next_rp >= 0 && !V_bfs[lp][next_rp] && next_rp > lp) {
                // printf("    Adding neighbor: %d %d\n", lp, rp - 1);
                Q.push({ D[next_rp].first - D[lp].first, { lp, next_rp } });
                V_bfs[lp][next_rp] = true;
            }
        }
        return 0;
    }
};
