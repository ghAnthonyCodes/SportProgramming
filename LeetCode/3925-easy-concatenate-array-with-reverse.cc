class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int N = (int)nums.size();
        nums.resize(2 * N);
        for (int i = 0; i < N; i++) nums[N + i] = nums[N - i - 1];
        return nums;
    }
};
