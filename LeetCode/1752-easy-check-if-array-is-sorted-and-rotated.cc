class Solution {
public:
  bool check(vector<int>& nums) {
    int x = nums[0];
    int segment = 0;
    int min_seg = x;
    for (auto n : nums) {
      if (n < x) segment++;
      if (segment > 1) return false;
      if (segment == 1) {
        if (n > min_seg) return false;
      }
      x = n;
    }
    return true;
  }
};
