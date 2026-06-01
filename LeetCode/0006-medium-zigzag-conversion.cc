class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int N = (int)s.size();
        vector<vector<char>> V = vector<vector<char>>(N, vector<char>(0));
        ostringstream os;
        // Add top row
        int row = 0;
        char dir = 0;
        for (int i=0; i<N; i++) {
            V[row].push_back(s[i]);
            if (dir == 0) row++;
            else row--;
            if (row == numRows) {
                dir = 1;
                row = numRows - 2;
            } else if (row == -1) {
                row = 1;
                dir = 0;
            }
        }
        for (int row = 0; row < min(N, numRows); row++) {
            for (auto& c : V[row]) {
                os << c;
            }
        }
        return os.str();
    }
};
