typedef vector<int> vi;
class Solution {
public:
    vi leftRightDifference(vi& nums) {
        int N = (int)nums.size();
        vi ls = vi(N, 0);
        vi rs = vi(N, 0);
        for (int n = 1; n < N; n++) ls[n] = ls[n - 1] + nums[n - 1];
        for (int n = N - 2; n >= 0; n--) rs[n] = rs[n + 1] + nums[n + 1];
        for (int n = 0; n < N; n++) nums[n] = abs(ls[n] - rs[n]);
        return nums;
    }
};
