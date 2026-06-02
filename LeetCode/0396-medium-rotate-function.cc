
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int N = nums.size();
        int full_sum = 0;
        int f0 = 0;
        for (int n=0; n<N; n++) {
            full_sum += nums[n];
            f0 += nums[n] * n;
        }

        // Solve
        int answer = f0;
        int fk = f0;
        for (int k=1; k<N; k++) {
            fk = fk - full_sum + nums[k - 1] * N;
            answer = max(answer, fk);
        }
        return answer;
    }
};
