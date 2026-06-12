typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

class Solution {
public:
    int maxArea(vi& height) {
        int N = (int)height.size();
        vpii D = vpii(N);
        for (int n = 0; n < N; n++)
            D[n] = { height[n], n };
        sort(D.begin(), D.end(), [](pii& a, pii& b) {
            return a.first > b.first;
        });

        int area = 0;
        for (int i = 0; i < N; i++) {
            if (D[i].first == 0) continue;
            for (int j = i + 1; j < N; j++) {
                if (D[j].first == 0) continue;
                int minimum_required_length = area / D[j].first;
                if (minimum_required_length > max(D[i].second, N - D[i].second))
                    break;
                area = max(area, D[j].first * abs(D[i].second - D[j].second));
            }
        }
        return area;
    }
};
