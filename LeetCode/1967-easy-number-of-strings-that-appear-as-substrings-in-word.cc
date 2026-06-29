class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int sol = 0;
        for (auto& pattern : patterns) {
            if (word.find(pattern) != string::npos) {
                sol++;
            }
        }
        return sol;
    }
};
