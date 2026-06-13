/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <set>
#include <queue>

typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

class Solution {
public:
    vc V;
    vi nums;
    void binary_search(TreeNode* parent, pii left_seg, pii right_seg) {
        int left_idx = left_seg.first + (left_seg.second - left_seg.first) / 2;
        int right_idx = right_seg.first + (right_seg.second - right_seg.first) / 2;
        if (!V[left_idx]) {
            V[left_idx] = 1;
            TreeNode* left_node = new TreeNode(nums[left_idx]);
            parent->left = left_node;
            binary_search(left_node, { left_seg.first, left_idx - 1 }, { left_idx + 1, left_seg.second });
        }

        if (right_idx < nums.size() && !V[right_idx]) {
            V[right_idx] = 1;
            TreeNode* right_node = new TreeNode(nums[right_idx]);
            parent->right = right_node;
            binary_search(right_node, { right_seg.first, right_idx - 1 }, { right_idx + 1, right_seg.second });
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int N = (int)nums.size();
        this->nums = nums;
        V = vc(N);
        int mid_idx = (N - 1) / 2;
        TreeNode* root = new TreeNode(nums[mid_idx]);
        V[mid_idx] = 1;
        binary_search(root, { 0, mid_idx - 1 }, { mid_idx + 1, N - 1 });
        return root;
    }
};
