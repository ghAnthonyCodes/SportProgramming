class Solution {
public:
    string processStr(string s) {
        vector<char> sol;
        for (auto& c : s) {
            if (c >= 'a' && c <= 'z') sol.push_back(c);
            else if (c == '*' && sol.size() > 0) sol.pop_back();
            else if (c == '#' && sol.size() > 0) sol.insert(sol.end(), sol.begin(), sol.end());
            else if (c == '%' && sol.size() > 0) reverse(sol.begin(), sol.end());
        }
        ostringstream os;
        for (auto&c : sol) os << c;
        return os.str();
    }
};
