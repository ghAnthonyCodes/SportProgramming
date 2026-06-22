typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    vi findDegrees(vvi& matrix) {
        int N = (int)matrix.size();
        vi sol = vi(N, 0);
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (matrix[i][j] == 1) {
                    sol[i]++;
                    sol[j]++;
                }
            }
        }
        return sol;
    }
};
