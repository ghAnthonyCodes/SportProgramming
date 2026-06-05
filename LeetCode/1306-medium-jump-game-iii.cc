#include <queue>

typedef std::vector<int> vi;
typedef std::vector<char> vc;
typedef std::queue<int> qi;

class Solution {
public:
    bool canReach(vi& arr, int start) {
        int N = (int)arr.size();
        vc V = vc(arr.size(), 0);
        qi Q = qi();

        Q.push(start);
        V[start] = true;

        while (!Q.empty()) {
            int idx = Q.front();
            Q.pop();
            if (arr[idx] == 0)
                return true;

            // Push neighbors
            int rc = idx + arr[idx];
            int lc = idx - arr[idx];
            if (rc < N && !V[rc]) {
                V[rc] = 1;
                Q.push(rc);
            }
            if (lc >= 0 && !V[lc]) {
                V[lc] = 1;
                Q.push(lc);
            }
        }
        return false;
    }
};
