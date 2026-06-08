typedef vector<int> vi;

class Solution {
public:
    vi pivotArray(vi& nums, int pivot) {
        int N = (int)nums.size();
        vi R; R.reserve(N);
        int nptr = 0;
        int p_count = 0;
        for (auto& n : nums) {
            if (n < pivot) nums[nptr++] = n;
            else if (n > pivot) R.push_back(n);
            else p_count++;
        }
        for (int i = 0; i < p_count; i++) nums[nptr++] = pivot;
        for (auto& r : R) nums[nptr++] = r;
        return nums;
    }
};
