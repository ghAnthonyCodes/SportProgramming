#include <queue>

typedef vector<int> vi;
typedef vector<char> vc;
typedef queue<int> qi;

class Solution {
public:

    bool canReach(string s, int min_jump, int max_jump) {
        int N = (int)s.size();
        vc V = vc(N, 0);
        qi Q;
        Q.push(0);
        V[0] = 1;
        int max_range_covered = 0;

        while (!Q.empty()) {
            int n = Q.front(); Q.pop();
            // printf("n=%d\n", n);
            if (n == N - 1) return true;

            // Push neighbors
            for (int candidate = max(max_range_covered, n + min_jump); candidate <= min(N - 1, n + max_jump); candidate++) {
                max_range_covered = max(max_range_covered, candidate);
                // printf("    Testing: %d\n", candidate);
                if (V[candidate] == 1 || s[candidate] == '1') continue;
                // printf("        Pushing: %d\n", candidate);
                Q.push(candidate);
                V[candidate] = 1;
            }
        }
        return false;
    }
};
