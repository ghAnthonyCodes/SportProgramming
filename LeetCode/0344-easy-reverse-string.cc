class Solution {
public:
    void reverseString(vector<char>& s) {
        int N = (int)s.size();
        int lp = 0; int rp = N - 1;
        while (lp < rp) {
            char temp = s[lp];
            s[lp] = s[rp];
            s[rp] = temp;
            lp++; rp--;
        }
    }
};
