typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vi> vvi;

class Solution {
public:
    void dfs(int node, vvi& graph, vi& V, int depth, int* max_depth) {
        V[node] = 1;
        *max_depth = max(*max_depth, depth);
        for (auto& child : graph[node]) {
            if (!V[child]) {
                dfs(child, graph, V, depth + 1, max_depth);
            }
        }
    }

    int assignEdgeWeights(vvi& edges) {
        int N = 0;
        for (auto& edge : edges) {
            N = max(N, edge[0]);
            N = max(N, edge[1]);
        }
        vvi graph = vvi(N + 1);
        vi V = vi(N + 1, 0); // max depth
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int max_depth = 0;
        dfs(1, graph, V, 0, &max_depth);
        
        // printf("Max Depth: %d\n", max_depth);
        int sol = 1;
        while (--max_depth > 0) {
            sol *= 2;
            if (sol > 1000000007LL)
                sol = sol - 1000000007LL;
        }
        return sol;
    }
};
