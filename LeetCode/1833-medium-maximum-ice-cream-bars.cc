typedef vector<int> vi;

class Solution {
public:
    int maxIceCream(vi& costs, int coins) {
        int N = (int)costs.size();
        int M = *max_element(costs.begin(), costs.end());
        vi H = vi(M + 1, 0);
        for (auto& c : costs) H[c]++;
        int sol = 0;
        for (int cost = 0; cost < (int)H.size(); cost++) {
            if (cost > coins) break;
            if (H[cost] > 0) {
                int k = min(coins / cost, H[cost]);
                sol += k;
                coins -= k * cost;
            }
        }
        return sol;
    }
};
