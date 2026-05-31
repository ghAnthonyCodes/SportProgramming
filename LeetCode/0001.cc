/*
Problem Link: https://leetcode.com/problems/two-sum
 */
#include <map>
typedef vector<int> vi;
typedef map<int, int> mii;

class Solution {
public:
    vector<int> twoSum(vi& nums, int target) {
        mii M;
        for (int i = 0; i < nums.size(); i++)
            M[nums[i]] = i;
        
        for (int i = 0; i < nums.size(); i++) {
            if (M.find(target - nums[i]) != M.end()) {
                if (i != M[target - nums[i]])
                    return { i, M[target - nums[i]] };
            }
        }
        return { };
    }
};
