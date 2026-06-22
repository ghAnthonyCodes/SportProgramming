typedef vector<char> vc;
typedef vector<vc> vvc;

class Solution {
public:
    bool check_range(vvc& board, int rs, int re, int cs, int ce) {
        vc x = vc(9, 0);
        for (int row = rs; row < re; row++) {
            for (int col = cs; col < ce; col++) {
                char c = board[row][col];
                if (c == '.') continue;
                if (x[c - '1'] != 0) return false;
                x[c - '1'] = 1;
            }
        }
        return true;
    }

    bool isValidSudoku(vvc& board) {
        bool sol = true;
        for (int row = 0; row < 9; row++) 
            sol &= check_range(board, row, row + 1, 0, 9);
        for (int col = 0; col < 9; col++) 
            sol &= check_range(board, 0, 9, col, col + 1);
        vector<vector<int>> S = { 
            { 0, 3, 0, 3 },
            { 3, 6, 0, 3 },
            { 6, 9, 0, 3 },
            { 0, 3, 3, 6 },
            { 3, 6, 3, 6 },
            { 6, 9, 3, 6 },
            { 0, 3, 6, 9 },
            { 3, 6, 6, 9 },
            { 6, 9, 6, 9 }
        };

        for (auto& s : S) 
            sol &= check_range(board, s[0], s[1], s[2], s[3]);
        return sol;
    }
};
