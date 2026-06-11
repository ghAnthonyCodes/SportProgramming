typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    void dfs(int n, int p, vvi& T, vvi& parent, vi& depth, int current_depth) {
        parent[n][0] = p;
        depth[n] = current_depth;

        for (auto& child : T[n]) {
            if (child != p) dfs(child, n, T, parent, depth, current_depth + 1);
        }
    }

    vi assignEdgeWeights(vvi& edges, vvi& queries) {
        int n = 0;
        for (auto& edge : edges) n = max(n, max(edge[0], edge[1]));
        int level = floor(log2(n - 1));
        vvi T = vvi(n + 1);
        vi quick_sol = vi(n + 1, 0);
        quick_sol[1] = 1;
        for (int i = 2; i <= n; i++) {
            quick_sol[i] = (2 * quick_sol[i - 1]) % 1000000007;
        }
        for (auto& edge : edges) {
            T[edge[0]].push_back(edge[1]);
            T[edge[1]].push_back(edge[0]);
        }
        vi depth = vi(n + 1, 0);
        vvi parent = vvi(n + 1, vi(level + 1, 0));

        // Calculate parent[u][0] (2^0th parent for each node)
        dfs(1, 0, T, parent, depth, 0);

        // Now we need to build up sparse matrix
        for (int i = 1; i <= level; i++) {
            for (int j = 2; j <= n; j++) {
                parent[j][i] = parent[parent[j][i - 1]][i - 1];
            }
        }

        /*
        for (int j = 1; j <= n; j++) {
            printf("parent[%d][...] =", j);
            for (int i = 0; i <= level; i++) {
                printf(" %d", parent[j][i]);
            }
            printf("\n");
        }*/

        // Now we simply solve the queries...
        vi solutions = vi((int)queries.size());
        int sol = 0;
        for (auto& query : queries) {
            // printf("Q(%d, %d)\n", query[0], query[1]);
            int u = query[0];
            int v = query[1];
            if (depth[v] < depth[u]) swap(u, v);
            // printf("   Q'(%d, %d)\n", u, v);
            int u_orig = u;
            int v_orig = v;
            int difference = depth[v] - depth[u];
            // printf("    diff(%d, %d) = %d\n", u, v, difference);

            // Bring u up to v
            int power = 0;
            while (difference > 0) {
                if (difference & 1) {
                    v = parent[v][power];
                }
                difference >>= 1;
                power++;
            }
            // printf("    updated v: %d\n", v);

            int common_depth;
            if (u == v) common_depth = depth[u];
            if (u != v) {

                // Now scan level downward to find answer
                for (int i = level; i >= 0; i--) {
                    if (parent[u][i] != parent[v][i]) {
                        u = parent[u][i];
                        v = parent[v][i];
                    }
                }
                common_depth = depth[parent[u][0]];
            }

            // The answer is 
            // printf("    common_depth: %d\n", depth[u]);
            int u_depth = depth[u_orig] - common_depth;
            int v_depth = depth[v_orig] - common_depth;
            // printf("    ancestor -> u_orig: %d\n", u_depth);
            // printf("    ancestor -> v_orig: %d\n", v_depth);
            // printf("u_depth: %d, v_depth: %d\n", u_depth, v_depth);
            int total_depth = u_depth + v_depth;
            // printf("Total depth: %d\n", total_depth);
            if (total_depth == 0) {
                solutions[sol++] = 0;
                continue;
            }
            solutions[sol++] = quick_sol[total_depth];
        }
        return solutions;
    }
};
