typedef long long ll;
typedef unsigned long long ull;
class Solution {
public:
    ull calc_size(string& s) {
        ull size = 0;
        for (auto& c : s) {
            if (c == '*') {
                if (size > 0) size--;
            }
            else if (c == '#') size *= 2;
            else if (c == '%') continue;
            else size++;
        }
        return size;
    }
    char processStr(string s, ll k) {
        int N = (int)s.size();
        ull S = calc_size(s);
        if (S == 0 || k >= S) return '.';
        // Backwards process k by iterating through s backwards
        for (int i = 0; i < N; i++) {
            char c = s[N - i - 1];
            if (c == '*') {
                S++;
            }
            else if (c == '#') {
                if (S == 0) continue;
                S = S / 2ULL;
                k = k % S;
            }
            else if (c == '%') {
                if (S <= 1) k = k;
                else if (S % 2 == 0) k = S - k - 1;
                else k = S - k - 1;
            }
            else {
                S--;
                if (S == k) return c;
            }
        }
        return '.';
    }
};
