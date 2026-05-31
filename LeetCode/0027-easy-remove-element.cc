class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int write_ptr = 0;
        for (auto& c : nums) 
            if (c != val) nums[write_ptr++] = c;
        return write_ptr;
    }
};
