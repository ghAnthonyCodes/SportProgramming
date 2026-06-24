#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

/* Shamelessly using the editorial for this one... */
class Solution {
public:
    ll MOD = 1000000007;
    vvll mult(vvll A, vvll B) {
        int n = A.size();
        int m = B[0].size();
        vvll C = vvll(n, vll(m, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < A[0].size(); k++) {
                ll r = A[i][k];
                if (r == 0) continue;
                for (int j = 0; j < m; j++)
                    C[i][j] = (C[i][j] + r * B[k][j]) % MOD;
            }
        }
        return C;
    }
    int zigZagArrays(int N, int l, int r) {
        int m = r - l + 1;

        // dp_decreasing[i] = dp_increasing[i - 1] * B
        // dp_increasing[i] = dp_decreasing[i - i] * A
        // Define D as [dp_decreasing, dp_increasing], a 1x2m matrix
        vvll D = vvll(1, vll(2 * m, 1));
        vvll U = vvll(2 * m, vll(2 * m, 0));

        // Init A within U
        for (int row = 0; row < m; row++) {
            for (int col = row + 1; col < m; col++) {
                U[row][m + col] = 1;
            }
        }

        // Init B within U
        for (int row = 1; row < m; row++) {
            for (int col = 0; col < row; col++) {
                U[m + row][col] = 1;
            }
        }
        
        // Solve via matrix exponentiation
        ll exp = N - 1;
        while (exp > 0) {
            if (exp & 1) D = mult(D, U);
            U = mult(U, U);
            exp >>= 1;
        }

        ll sol = 0;
        for (int i = 0; i < m; i++) {
            sol = (sol + D[0][i]) % MOD;
        }
        return (2LL * sol) % MOD;
    }
};
