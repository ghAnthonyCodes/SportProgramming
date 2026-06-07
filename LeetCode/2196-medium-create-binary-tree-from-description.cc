typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution {
public:

    TreeNode* createBinaryTree(vvi& descriptions) {
        
        vector<TreeNode *> tree = vector<TreeNode *>(100001, nullptr);
        vi parents = vi(100001, 0);
        for (auto& desc : descriptions) {
            if (tree[desc[0]] == nullptr) tree[desc[0]] = new TreeNode(desc[0]);
            if (tree[desc[1]] == nullptr) tree[desc[1]] = new TreeNode(desc[1]);
            if (desc[2] == 1) tree[desc[0]]->left = tree[desc[1]];
            else tree[desc[0]]->right = tree[desc[1]];
            parents[desc[1]] = desc[0];
        }
        int root_idx = descriptions[0][0];
        while (parents[root_idx] != 0) root_idx = parents[root_idx];
        return tree[root_idx];
    }
};
