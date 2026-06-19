class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int a = 0; int sol = 0;
        for (auto& g : gain) {
            a += g;
            sol = max(sol, a);
        }
        return sol;
    }
};
