class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int N = (int)cost.size();
        std::sort(cost.begin(), cost.end(), [](int a, int b) { return a > b; });
        int answer = 0;
        int pump = 0;
        for (int n=0; n<N; n++) {
            if (pump == 2) {
                pump = 0; 
                continue;
            }
            answer += cost[n];
            pump++;
        }
        return answer;
    }
};
