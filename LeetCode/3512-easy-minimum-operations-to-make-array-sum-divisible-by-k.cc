class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int total = 0;
        for (auto& n : nums) total += n;
        return total % k;
    }
};
