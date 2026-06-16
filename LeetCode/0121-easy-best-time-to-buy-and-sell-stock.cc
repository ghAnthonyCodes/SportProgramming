class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best_min_seen = 1e5;
        int sol = 0;
        for (int i = 0; i < prices.size(); i++) {
            best_min_seen = min(prices[i], best_min_seen);
            sol = max(prices[i] - best_min_seen, sol);
        }
        return sol;
    }
};
