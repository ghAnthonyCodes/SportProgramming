typedef vector<int> vi;

class SegTree {
private:
    int n;
    vi tree;
public:
    SegTree (const vi& arr, int target) {
        n = arr.size();

        // Exact size of 2 * N is enough
        tree.resize(2 * n, 0); 

        // Insert leaf nodes into the second half of the tree array
        for (int i = 0; i < n; i++)
            tree[n + i] = (int)(arr[i] == target);

        // Build the tree parents bottom-up
        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[i << 1] + tree[i << 1 | 1]; // Parent = Left + Right
        }
    }

    int query(int l, int r) {  // sum on interval [l, r)
        int res = 0;
        // Loop moves up to parents by dividing pointers by 2 (shift right)
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += tree[l++]; // If L is a right child, include it and move right
            if (r & 1) res += tree[--r]; // If R is a right child, drop down to left child and include it
        }
        return res;
    }
};

class Solution {
public:
    int countMajoritySubarrays(vi& nums, int target) {
        int N = (int)nums.size();
        int sol = 0;
        SegTree tree = SegTree(nums, target);
        for (int l = 0; l < N; l++) {
            for (int r = l + 1; r <= N; r++) {
                if (tree.query(l, r) >= (r - l) / 2 + 1) {
                    sol++;
                }
            }
        }
        return sol;
    }
};
