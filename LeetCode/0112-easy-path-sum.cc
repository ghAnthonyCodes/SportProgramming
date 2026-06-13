class Solution {
public:
    int target;
    bool dfs(TreeNode* n, int sum) {
        if (n->left == nullptr && n->right == nullptr) return sum == target;
        bool sol = false;
        if (n->left != nullptr) sol = sol || dfs(n->left, sum + n->left->val);
        if (n->right != nullptr) sol = sol || dfs(n->right, sum + n->right->val);
        return sol;
        
    }
    bool hasPathSum(TreeNode* root, int target) {
        this->target = target;
        if (root == nullptr) return false;
        return dfs(root, root->val);
    }
};
