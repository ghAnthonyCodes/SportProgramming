typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    vvi generate(int numRows) {
        if (numRows == 1) return { { 1 } };
        if (numRows == 2) return { { 1 }, { 1, 1 } };
        vvi sol = { { 1 }, { 1, 1 } };
        for (int row = 2; row < numRows; row++) {
            sol.push_back({ 1 });
            for (int j = 1; j < row; j++) {
                // printf("sol[%d].push_back(sol[%d][%d] + sol[%d][%d])\n", row, row-1, j, row - 1, j - 1);
                sol[row].push_back(sol[row - 1][j] + sol[row - 1][j - 1]);
            }
            sol[row].push_back(1);
        }
        return sol;
    }
};
