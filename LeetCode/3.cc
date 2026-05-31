#include <set>
typedef set<char> sc;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        int l=0; int r=0; int N = (int)s.size();
        sc S = { };
        int max_substr = 0;
        while (1) {
            // Expand right until we hit a dupe
            while (S.find(s[r]) == S.end()) {
                S.insert(s[r++]);
                max_substr = max(max_substr, (int)S.size());
                if (r == N) return max_substr;
            }

            // Move left until we delete S[r]
            while (s[l] != s[r]) {
                S.erase(s[l]);
                l++;
            }
            S.erase(s[l++]);
        }
        return 0;
    }
};
