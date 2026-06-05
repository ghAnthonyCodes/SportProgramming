#include <queue>
#include <set>

typedef unordered_set<int> si;
typedef vector<int> vi;
typedef unordered_map<int, int> mii;
typedef queue<int> qi;

class Solution {
    /* Once you push the fringe, there is a theoretically best answer.
        Given that you push a number x, if the answer were to exist
        within the fringe it would be N - 1 - x.

    */
public:
    int minJumps(vector<int>& arr) {

        // Preprocessing
        int N = (int)arr.size();
        auto comp = [](int lhs, int rhs) { return lhs > rhs; };
        map<int, set<int, decltype(comp)>> ja;
        for (int n=0; n<N; n++) {

            // Check for completely irrelavent numbers
            if (n > 0 && n < N - 1 && arr[n] == arr[n-1] && arr[n] == arr[n + 1])
                continue;
            if (ja.find(arr[n]) == ja.end())
                ja[arr[n]] = { n };
            else
                ja[arr[n]].insert(n);
        }

        mii d; qi Q; si F;
        Q.push(0);
        d[0] = 0;

        while (!Q.empty()) {
            int n = Q.front(); Q.pop();
            if (n == N - 1) return d[n];

            // Go left
            if (n - 1 >= 0 && d.find(n - 1) == d.end()) {
                // printf("Pushing: %d\n", n - 1);
                Q.push(n - 1);
                d[n - 1] = d[n] + 1;
            }

            // Go right
            if (n + 1 < N && d.find(n + 1) == d.end()) {
                // printf("Pushing: %d\n", n + 1);
                Q.push(n + 1);
                d[n + 1] = d[n] + 1;
            }

            // Fancy jumps
            if (F.find(arr[n]) != F.end()) 
                continue;
            for (auto jn : ja[arr[n]]) {
                if (jn == n) continue;
                if (d.find(jn) == d.end()) {
                    Q.push(jn);
                    d[jn] = d[n] + 1;
                }
            }

            // Add this number to fringe numbers
            F.insert(arr[n]);
        }
        return 0;
    }
};
