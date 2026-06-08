class Solution {
public:
    void dfs(TreeNode* n, vector<int>& sol) {
        if (n->left != nullptr)
            dfs(n->left, sol);
        sol.push_back(n->val);
        if (n->right != nullptr)
            dfs(n->right, sol);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return { };
        vector<int> V;
        dfs(root, V);
        return V;
    }
};
