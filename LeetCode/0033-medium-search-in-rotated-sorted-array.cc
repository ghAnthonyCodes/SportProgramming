typedef vector<int> vi;

class Solution {
public:
    int findMin(vi& nums) {
        int N = (int)nums.size();
        int lo = 0; int hi = N - 1;

        for (int i=0; i<13; i++) {
            if (hi == lo) return hi;
            int m = lo + (hi - lo) / 2;
            if (nums[m] > nums[hi]) lo = m + 1;
            else hi = m;
        }
        return 0;
    }

    int bs(vi& nums, int target, int lo, int hi) {
        for (int i=0; i<13; i++) {
            int m = lo + (hi - lo) / 2;
            if (nums[m] == target) return m;
            if (hi == lo) break;
            if (nums[m] < target) lo = m + 1;
            else hi = m;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int N = (int)nums.size();
        int min_n = this->findMin(nums);
        int candidate_a = this->bs(nums, target, 0, max(0, min_n - 1));
        int candidate_b = this->bs(nums, target, min_n, N - 1);
        return max(candidate_a, candidate_b);
    }
};
