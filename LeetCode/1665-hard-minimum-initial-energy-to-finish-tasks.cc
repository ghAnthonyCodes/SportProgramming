typedef std::vector<int> vi;
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        
        std::sort(tasks.begin(), tasks.end(), [](vi& a, vi& b) {
            int gap_a = a[1] - a[0];
            int gap_b = b[1] - b[0];
            if (gap_a == gap_b)
                return a[1] == b[1] ? a[0] > b[0] : a[1] > b[1];
            return gap_a > gap_b;
        });
        
        int tot = tasks[0][1];
        int rem = tot - tasks[0][0];
        for (int n = 1; n < (int)tasks.size(); n++) {
            if (tasks[n][1] > rem) {
                tot += tasks[n][1] - rem;
                rem = tasks[n][1] - tasks[n][0];
            } else {
                rem -= tasks[n][0];
            }
        }
        return tot;
    }
};
