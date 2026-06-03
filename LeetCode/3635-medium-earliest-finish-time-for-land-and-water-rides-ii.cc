typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
class Solution {
public:
    int earliestFinishTime(vi& lsts, vi& lds, vi& wsts, vi& wds) {
        int N = (int)lsts.size(); int M = (int)wsts.size();
        int elft = 1e6;
        int ewft = 1e6;
        int sol = 1e6;

        // o(100)
        for (int n=0; n<N; n++) elft = min(elft, lsts[n] + lds[n]);

        // o(100)
        for (int m=0; m<M; m++) ewft = min(ewft, wsts[m] + wds[m]);

        // o(100)
        for (int m=0; m<M; m++) {
            if (elft <= wsts[m]) sol = min(sol, wsts[m] + wds[m]);
            else sol = min(sol, elft + wds[m]);
        }

        // o(100)
        for (int n=0; n<N; n++) {
            if (ewft <= lsts[n]) sol = min(sol, lsts[n] + lds[n]);
            else sol = min(sol, ewft + lds[n]);
        }

        return sol;
    }
};
