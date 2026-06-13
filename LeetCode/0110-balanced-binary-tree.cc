class Solution {
public:
    bool is_balanced = true;
    int dfs(TreeNode* node, int depth) {
        if (node->left == nullptr && node->right == nullptr) return depth;
        int left_depth = depth;
        int right_depth = depth;
        if (node->left != nullptr) left_depth = dfs(node->left, depth + 1);
        if (node->right != nullptr) right_depth = dfs(node->right, depth + 1);
        if (abs(left_depth - right_depth) >= 2) is_balanced = false;
        return max(left_depth, right_depth);
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        dfs(root, 0);
        return is_balanced;
    }
};
