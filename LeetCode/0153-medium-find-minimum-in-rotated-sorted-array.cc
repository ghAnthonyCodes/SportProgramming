typedef vector<int> vi;

// 1 2 3 4 5
// 5 1 2 3 4
// 4 5 1 2 3

class Solution {
public:
    int findMin(vi& nums) {
        int N = (int)nums.size();
        int lo = 0; int hi = N - 1;

        for (int i=0; i<13; i++) {
            if (hi == lo) return nums[hi];
            int m = lo + (hi - lo) / 2;
            if (nums[m] > nums[hi]) lo = m + 1;
            else hi = m;
        }
        return 0;
    }
};
