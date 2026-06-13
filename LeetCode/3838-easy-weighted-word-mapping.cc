class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        ostringstream os;
        for (auto& word : words) {
            int sum = 0;
            for (auto& c : word) 
                sum += weights[c - 'a'];
            os << (char)('z' - (sum % 26));
        }
        return os.str();
    }
};
