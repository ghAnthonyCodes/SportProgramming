class Solution {
public:
    bool asteroidsDestroyed(int M, vector<int>& A) {
        sort(A.begin(), A.end());
        unsigned long long x = M;
        for (auto& a : A) {
            if (a > x) return false;
            x += a;
        }
        return true;
    }
};
