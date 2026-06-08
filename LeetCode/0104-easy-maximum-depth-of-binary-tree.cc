class Solution {
public:
    void dfs(TreeNode* n, int depth, int *max_depth) {
        if (n == nullptr) return;
        *max_depth = max(depth, *max_depth);
        dfs(n->left, depth + 1, max_depth);
        dfs(n->right, depth + 1, max_depth);
    }
    int maxDepth(TreeNode* root) {
        int answer = 0;
        dfs(root, 1, &answer);
        return answer;
    }
};
