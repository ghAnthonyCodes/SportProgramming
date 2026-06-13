class Solution {
public:
    int dfs(TreeNode* root, int depth) {
        if (root->left == nullptr && root->right == nullptr) return depth;
        int min_d = 1e6;
        if (root->left != nullptr) min_d = dfs(root->left, depth + 1);
        if (root->right != nullptr)
            return min(min_d, dfs(root->right, depth + 1));
        return min_d;  
    }
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return dfs(root, 1);
    }
};
