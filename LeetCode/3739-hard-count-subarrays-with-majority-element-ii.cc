typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

class Solution {
public:
    ll countMajoritySubarrays(vector<int>& nums, int target) {
        int N = (int)nums.size();
        ll sol = 0;
        vi S = vi(N + 1, 0);
        vi P = vi(2 * (N + 1), 0);
        P[N] = 1;
        int count = N;
        ll presum = 0;

        // Transform array into +1s and -1s
        for (int i = 0; i < N; i++) {
            if (nums[i] == target) nums[i] = 1;
            else nums[i] = -1;
        }
        
        for (int i = 0; i < N; i++) {
            S[i + 1] = S[i] + nums[i];
            if (nums[i] == 1) {
                presum += P[S[i] + N];

            } else {
                presum -= P[S[i + 1] + N];
            }
            P[S[i + 1] + N]++;
            sol += presum;
        }
        return sol;
    }
};
