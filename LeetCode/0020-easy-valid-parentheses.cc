#include <vector>
typedef std::vector<char> vc;

class Solution {
public:
    bool isValid(string s) {
        vc stack;
        stack.reserve((int)s.size());
        for (const auto& c : s) {
            if (c == ')') {
                if (stack.empty() || stack.back() != '(') 
                    return false;
                stack.pop_back();
            } else if (c == ']') {
                if (stack.empty() || stack.back() != '[') 
                    return false;
                stack.pop_back();
            } else if (c == '}') {
                if (stack.empty() || stack.back() != '{') 
                    return false;
                stack.pop_back();
            } else {
                stack.push_back(c);
            }
        }
        return stack.empty();
    }
};
