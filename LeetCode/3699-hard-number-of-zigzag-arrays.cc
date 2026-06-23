#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;

class Solution {
public:
    int zigZagArrays(int N, int l, int r) {
        long long MOD = 1000000007;

        vvvi D = vvvi(N, vvi(2, vi(r - l + 1, 0)));
        vvvi S = vvvi(N, vvi(2, vi(r - l + 2, 0)));

        // Init D
        for (int lo = 0; lo < 2; lo++) {
            for (int k = l; k <= r; k++) {
                D[0][lo][k - l] = 1;
                S[0][lo][k - l + 1] = k - l + 1;
            }
        }

        // DP Transitions
        for (int n = 1; n < N; n++) {
            int running_total_0 = 0;
            int running_total_1 = 0;

            for (int k = l; k <= r; k++) {
                D[n][1][k - l] = (((ll)S[n - 1][0][r - l + 1] - S[n - 1][0][k - l + 1]) + MOD) % MOD;
                D[n][0][k - l] = S[n - 1][1][k - l];
                S[n][0][k - l + 1] = (S[n][0][k - l] + D[n][0][k - l]) % MOD;
                S[n][1][k - l + 1] = (S[n][1][k - l] + D[n][1][k - l]) % MOD;
            }
        }

        // Aggregate Answer
        ll sol = 0;
        for (int i = l; i <= r; i++) {
            sol = (sol + D[N - 1][0][i - l]) % MOD;
            sol = (sol + D[N - 1][1][i - l]) % MOD;
        }
        
        return (int)(sol % MOD);
    }
};
