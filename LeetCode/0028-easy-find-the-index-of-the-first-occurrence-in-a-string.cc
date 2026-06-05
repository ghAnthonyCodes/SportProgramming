class Solution {
public:
    int strStr(string haystack, string needle) {
        int N = (int)haystack.size();
        int M = (int)needle.size();
        for (int i = 0; i <= N - M; i++) {
            if (haystack.substr(i, M) == needle)
                return i;
        }
        return -1;
    }
};
