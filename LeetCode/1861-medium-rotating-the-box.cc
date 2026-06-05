typedef vector<char> vc;
typedef vector<vector<char>> vvc;

class Solution {
public:
    vvc rotateTheBox(vvc& G) {

        // 
        vvc R = vvc(G[0].size(), vc(G.size(), '.'));

        for (int r=0; r<G.size(); r++) {
            int stone_count = 0;
            for (int c=0; c<G[0].size(); c++) {
                if (G[r][c] == '*') {
                    R[c][G.size() - r - 1] = '*';
                    int starting_c = c - 1;
                    while (stone_count > 0) {
                        R[starting_c--][G.size() - r - 1] = '#';
                        stone_count--;
                    }
                }
                else if (G[r][c] == '#') stone_count++;
            }
            int starting_c = G[0].size() - 1;
            while (stone_count > 0) {
                R[starting_c--][G.size() - r - 1] = '#';
                stone_count--;
            }
        }
        return R;
    }
};
