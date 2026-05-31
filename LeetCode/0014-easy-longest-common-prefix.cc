class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_str_size = strs[0].size();
        for (const auto& s : strs)
            min_str_size = std::min(min_str_size, (int)s.size());
        // Calc answer
        std::ostringstream answer;
        for (int s=0; s<min_str_size; s++) {
            char matching = strs[0][s];
            for (const auto& st : strs) {
                if (st[s] != matching)
                    return answer.str();
            }
            answer << matching;
        }
        return answer.str();
    }
};
