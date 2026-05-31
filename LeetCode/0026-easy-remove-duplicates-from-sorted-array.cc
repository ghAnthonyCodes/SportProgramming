class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<char> D = vector<char>(203, 0);
        for (int i=0; i<(int)nums.size(); i++)
            D[nums[i] + 100] = 1;
        int ptr = 0;
        for (int i=0; i<203; i++)
            if (D[i] == 1)
                nums[ptr++] = i - 100;
        return ptr;
    }
};
