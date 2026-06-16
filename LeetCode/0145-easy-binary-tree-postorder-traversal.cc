typedef vector<int> vi;

class Solution {
public:
    void dfs(TreeNode* node, vi& sol) {
        if (node->left != nullptr) dfs(node->left, sol);
        if (node->right != nullptr) dfs(node->right, sol);
        sol.push_back(node->val);
    }
    vi postorderTraversal(TreeNode* root) {
        if (root == nullptr) return { };
        vi sol;
        dfs(root, sol);
        return sol;
    }
};
