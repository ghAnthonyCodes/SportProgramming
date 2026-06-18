typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pair<int, int>> vpii;

class Solution {
public:
    vvi threeSum(vi& nums) {
        vvi sol;
        set<tuple<int, int, int>> seen;
        int N = (int)nums.size();
        sort(nums.begin(), nums.end());
        int last_start = 1e6;
        for (int i = 0; i < N - 2; i++) {
            // lowest number possible as starting point
            // if positive, no possible combination to reach 0
            // if negative, the way to get out of it is with another 2 numbers
            int a = nums[i];
            if (a > 0) break;
            if (a == last_start) continue;
            last_start = a;

            // highest number possible
            for (int j = N - 1; j > i + 1; j--) {
                int b = nums[j];
                int min_possible = a + a + b;
                int max_possible = a + b + b;
                if (min_possible > 0 || max_possible < 0) continue;

                for (int k = j - 1; k > i; k--) {
                    int c = nums[k];
                    if (a + b + c == 0) {
                        if (seen.find({ a, b, c }) == seen.end()) {
                            sol.push_back({ a, b, c });
                            seen.insert({ a, b, c });
                        }
                    } else if (a + b + c < 0) break;
                }
            }
        }
        return sol;
    }
};
