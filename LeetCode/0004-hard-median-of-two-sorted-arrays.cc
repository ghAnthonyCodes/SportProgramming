typedef vector<int> vi;

class Solution {
public:
    double findMedianSortedArrays(vi& A, vi& B) {
        int N = (int)A.size() + (int)B.size();
        int ptr = 0;
        vi s = vi(N);
        for (auto& a : A) s[ptr++] = a;
        for (auto& b : B) s[ptr++] = b;
        sort(s.begin(), s.end());
        if (N & 1) return s[(N - 1) / 2];
        return (s[N / 2] + s[N / 2 - 1]) / 2.f;
    }
};
