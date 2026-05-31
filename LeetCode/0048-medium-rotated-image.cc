class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = (int)m.size();
        for (int r=0; r<n/2; r++) {
            for (int c=r; c<n-r-1; c++) {
      
                // Rotation 1
                int ra = c;
                int ca = n - r - 1;

                int rb = ca;
                int cb = n - ra - 1;

                int rc = cb;
                int cc = n - rb - 1;

                // printf("(%d, %d), (%d, %d), (%d, %d), (%d, %d)\n", r, c, ra, ca, rb, cb, rc, cc);
                int tmp = m[r][c];
                m[r][c] = m[rc][cc];
                m[rc][cc] = m[rb][cb];
                m[rb][cb] = m[ra][ca];
                m[ra][ca] = tmp;
            }
        }
    }
};
