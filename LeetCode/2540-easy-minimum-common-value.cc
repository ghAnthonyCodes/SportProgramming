class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int a = 0; int b = 0; int A = (int)nums1.size(); int B = (int)nums2.size();
        int N = A + B;
        for (int i = 0; i < N; i++) {
            if (nums1[a] == nums2[b]) return nums1[a];
            if (nums1[a] < nums2[b]) {
                if (++a == A) return -1;
            } else {
                if (++b == B) return -1;
            }
        }
        return 0;
    }
};
