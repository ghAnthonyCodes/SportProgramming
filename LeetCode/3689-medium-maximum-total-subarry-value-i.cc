typedef vector<int> vi;
typedef long long ll;

class Solution {
public:
    ll maxTotalValue(vi& nums, int k) {
        int x = nums[0];
        int y = nums[0];
        for (auto& n : nums) {
            x = max(x, n);
            y = min(y, n);
        }
        return ((ll)x - (ll)y) * (ll)k;
    }
};
