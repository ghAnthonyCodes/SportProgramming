class Solution {
public:
    int numberOfSubstrings(string s) {
        int N = (int)s.size();

        // Init D
        int D[3] = { 0, 0, 0 };
        D[s[0] - 'a']++;
        D[s[1] - 'a']++;
        D[s[2] - 'a']++;

        int lp = 0;
        int rp = 2;

        int sol = 0;
        
        while (1) {
            if (D[0] > 0 && D[1] > 0 && D[2]) {
                sol += N - rp;
                D[s[lp] - 'a']--;
                lp++;
            } else {
                rp++;
                if (rp == N) break;
                D[s[rp] - 'a']++;
            }
        }

        return sol;
    }
};
