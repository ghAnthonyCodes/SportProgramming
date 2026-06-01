class Solution {
public:
    string longestPalindrome(string s) {

        int N = (int)s.size();

        // Memoize
        vector<vector<char>> D = vector<vector<char>>(N, vector<char>(N, 0));
        
        int max_substr = 1;
        int max_substr_l = 0;
        int max_substr_r = 0;
        for (int x = 0; x < (int)s.size(); x++) {
            for (int y = N - 1; y > x; y--) {
                
                if (D[x][y] > 0) continue;
                int l = x;
                int r = y;
                // printf("Checking s[%d] with s[%d]\n", l, r);
                while (s[l] == s[r]) {
                    if (l == r || l > r || D[l][r] == 1) {
                        int substr_size = y - x + 1;
                        if (substr_size > max_substr) {
                            max_substr = substr_size;
                            max_substr_l = x;
                            max_substr_r = y;
                            D[x][y] = 1;
                        }
                        break;
                    }
                    D[l][r] = 1;
                    l++; r--;
                }
            }
        }

        // Build answer
        printf("%d %d\n", max_substr_l, max_substr);
        return s.substr(max_substr_l, max_substr);
    }
};
