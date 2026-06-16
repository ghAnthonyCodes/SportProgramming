class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> D = vector<int>(1e5, 2);
        for (auto& n : nums) D[n + 4e4]--;
        for (int i=0; i < 1e5; i++) if (D[i] == 1) return i - 4e4;
        return 0;
    }
};
