#include <queue>

typedef vector<int> vi;
typedef vector<char> vc;
typedef queue<int> qi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef map<int, int> mii;

class Solution {
public:
    void dfs(int node_idx, vi& arr, vi& D, int depth, int d, int N) {
        if (D[node_idx] >= depth) return;
        //printf("    dfs(arr[%d] = %d, with depth=%d)\n", node_idx, arr[node_idx], depth);
        D[node_idx] = depth;

        // Choose two neighbors wisely
        // Find best left neighbor
        int max_left_neighbor_value = 0;
        vi max_left_neighbor_indices;
        for (int i = 1; i <= d; i++) {
            int j = node_idx - i;
            if (j < 0) break;
            if (arr[j] >= arr[node_idx]) break;
            //printf("        Checking neighbor: arr[%d] = %d?\n", j, arr[j]);
            if (arr[j] > max_left_neighbor_value) {
                max_left_neighbor_value = arr[j];
                max_left_neighbor_indices = { j };
            } else if (arr[j] == max_left_neighbor_value) {
                max_left_neighbor_indices.push_back(j);
            }
        }

        // Find best right neighbor
        int max_right_neighbor_value = 0;
        vi max_right_neighbor_indices;
        for (int i = 1; i <= d; i++) {
            int j = node_idx + i;
            if (j == N) break;
            if (arr[j] >= arr[node_idx]) break;
            if (arr[j] > max_right_neighbor_value) {
                max_right_neighbor_value = arr[j];
                max_right_neighbor_indices = { j };
            } else if (arr[j] == max_right_neighbor_value) {
                max_right_neighbor_indices.push_back(j);
            }
        }

        // Explore neighbors
        for (auto jump_idx : max_left_neighbor_indices)
            dfs(jump_idx, arr, D, depth + 1, d, N);
        for (auto jump_idx : max_right_neighbor_indices)
            dfs(jump_idx, arr, D, depth + 1, d, N);
    }
    int maxJumps(vi& arr, int d) {
        int N = (int)arr.size();
        // The goal is to DFS, always jumping to the highest thing you can reach
        // which we can use a segtree for, but let's start with brute force
        vi D = vi(N, 0);
        vpii sorted_arr = vpii(N);
        for (int i=0; i<N; i++) 
            sorted_arr[i] = { arr[i], i };
        std::sort(sorted_arr.begin(), sorted_arr.end(), [](pii a, pii b) {
            return a.first > b.first;
        });
        
        for (int i=0; i<N; i++) {
            // printf("Starting DFS arr[%d] = %d\n", i, arr[i]);
            this->dfs(sorted_arr[i].second, arr, D, 1, d, N);
        }
        return *(max_element(D.begin(), D.end()));
    }
};
