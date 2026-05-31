class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo=0; int hi=(int)nums.size() - 1;
        while (1) {
            int s = lo + (hi - lo) / 2;
            
            if (nums[s] == target)
                return s;
            if (hi <= lo) {
                if (nums[s] > target) 
                    return s;
                else
                    return s + 1;
            }
            if (nums[s] < target) {
                lo = s + 1;
            } else {
                hi = s - 1;
            }
        }
    }
};
