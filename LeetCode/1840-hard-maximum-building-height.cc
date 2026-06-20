typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    int maxBuilding(int n, vvi& restrictions) {
        int N = (int)restrictions.size() + 1;
        vpii segs = vpii(N);
        segs[0] = { 0, 0 };  // Index, Max Height
        for (int i = 1; i < N; i++) segs[i] = { restrictions[i - 1][0] - 1, restrictions[i - 1][1] };
        sort(segs.begin(), segs.end(), [](pii& a, pii& b) { return a.first < b.first; });
        if (segs.back().first != n - 1) { segs.push_back({ n - 1, n - 1 }); N++; }
        
        // Modify segs based on known limits, left pass
        for (int i = 1; i < N; i++) {
            int Lx = segs[i - 1].first;
            int Lh = segs[i - 1].second;
            int Rx = segs[i].first;
            int Rh = min(segs[i].second, Lh + (Rx - Lx));
            segs[i] = { Rx, Rh };
        }

        // right pass
        for (int i = N - 1; i > 0; i--) {
            int Rx = segs[i].first;
            int Rh = segs[i].second;
            int Lx = segs[i - 1].first;
            int Lh = min(segs[i - 1].second, Rh + (Rx - Lx));
            segs[i - 1] = { Lx, Lh };
        }

        // solve
        int sol = 0;
        for (int i = 1; i < N; i++) {
            int Lx = segs[i - 1].first;
            int Lh = segs[i - 1].second;
            int Rx = segs[i].first;
            int Rh = segs[i].second;
            int kl = (Lx + Rx + Rh - Lh) / 2;  // siiiiick
            int candidate = Lh + (kl - Lx);
            if (candidate > sol) sol = candidate;
        }

        return sol;
    }
};
