class Solution {
public:
    void merge(vector<int>& solution, int m, vector<int>& B, int n) {
        int a = 0; int b = 0;
        vector<int> A = solution;
        for (int i = 0; i < m + n; i++) {
            if (a == m) solution[i] = B[b++];
            else if (b == n) solution[i] = A[a++];
            else if (A[a] < B[b]) solution[i] = A[a++];
            else solution[i] = B[b++];
        }
    }
};
