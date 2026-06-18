class Solution {
public:
    int bsearch(vector<int>& nums, int sum, int target, int lo, int hi) {
        // printf("    starting search\n");
        int closest_sum = 1e6;
        // int prev_m = 1e6;
        while (lo <= hi) {
            int m = lo + (hi - lo) / 2;
            int x = nums[m];
            // printf("    considering: nums[%d] = %d\n", m, x);
            if (abs(sum + x - target) < abs(closest_sum - target)) closest_sum = sum + x;
            // if (m == prev_m) return closest_sum;
            if (sum + x == target) return target;
            if (sum + x < target) lo = m + 1;
            if (sum + x > target) hi = m - 1;
            // prev_m = m;
        }
        return closest_sum;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int N = (int)nums.size();
        sort(nums.begin(), nums.end());
        int sol = 1e6;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                // printf("TC: %d, %d, _\n", nums[i], nums[j]);
                int sum = nums[i] + nums[j];
                int closest = bsearch(nums, sum, target, j + 1, N - 1);
                if (abs(closest - target) < abs(sol - target)) sol = closest;
            }
        }
        return sol;
    }
};
