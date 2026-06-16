class Solution {
public:
    void dfs(TreeNode* node, vector<int>& solution) {
        solution.push_back(node->val);
        if (node->left != nullptr) dfs(node->left, solution);
        if (node->right != nullptr) dfs(node->right, solution);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return { };
        vector<int> sol = { };
        dfs(root, sol);
        return sol;
    }
};
