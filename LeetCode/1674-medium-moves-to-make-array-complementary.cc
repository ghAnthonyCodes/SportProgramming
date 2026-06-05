typedef std::vector<int> vi;
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int N = (int)nums.size();
        int K = N / 2;
        vi T = vi(2 * limit + 2, 0);
        T[0] = 2 * K;  // to achieve 1, you'll need to change both numbers
        for (int k=0; k<K; k++) {
            T[std::min(nums[k], nums[N - k - 1]) + 1] -= 1;  // first dip
            T[nums[k] + nums[N - k - 1]] -= 1;
            T[nums[k] + nums[N - k - 1] + 1] += 1;
            T[std::max(nums[k], nums[N - k - 1]) + limit + 1] += 1;
        }
        
        int min_changes = 2 * N;
        int current_changes = 0;
        for (int t=0; t<=2*limit; t++) {
            current_changes += T[t];
            min_changes = std::min(min_changes, current_changes);
        }
        return min_changes;
    }
};
