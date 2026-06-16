class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums.size() > 2 ? nums[nums.size() / 2] : nums[0];
    }
};
