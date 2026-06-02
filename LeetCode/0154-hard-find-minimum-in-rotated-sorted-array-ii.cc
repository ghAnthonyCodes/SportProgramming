typedef vector<int> vi;
class Solution {
public:
    int findMin(vi& nums) {
        return *(std::min_element(nums.begin(), nums.end()));
    }
};
