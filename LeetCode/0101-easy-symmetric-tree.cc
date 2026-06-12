class Solution {
public:
    bool dfs(TreeNode* xl, TreeNode* xr) {
        if (xl == nullptr) return xr == nullptr;
        if (xr == nullptr) return xl == nullptr;
        if (xl->val != xr->val) return false;
        return dfs(xl->left, xr->right) && dfs(xl->right, xr->left);
    }
    bool isSymmetric(TreeNode* root) {
        auto left = root->left;
        auto right = root->right;
        return dfs(left, right);
    }
};
