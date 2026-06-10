class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> A;
        for (const auto& num : nums) {
            auto sn = std::to_string(num);
            for (const auto& c : sn) A.emplace_back(c - '0');
        }
        return A;
    }
};
