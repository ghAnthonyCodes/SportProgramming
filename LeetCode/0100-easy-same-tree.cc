class Solution {
public:
    bool is_same_dfs(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr && q != nullptr) return false;
        if (p != nullptr && q == nullptr) return false;
        if (p->val != q->val) return false;
        
        // Try left
        return is_same_dfs(p->left, q->left) && is_same_dfs(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return is_same_dfs(p, q);
    }
};
