typedef vector<string> vs;

class Solution {
public:
    vs letterCombinations(string digits) {
        int len = (int)digits.size();
        vs sol;
        string M[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        if (len == 1) {
            for (auto& a : M[digits[0] - '0']) {
                string x = "";
                x += a;
                sol.push_back(x);
            }
        }
        if (len == 2) {
            for (auto& a : M[digits[0] - '0']) {
                for (auto& b : M[digits[1] - '0']) {
                    string x = "";
                    x += a; x += b;
                    sol.push_back(x);
                }
            }
        }
        if (len == 3) {
            for (auto& a : M[digits[0] - '0']) {
                for (auto& b : M[digits[1] - '0']) {
                    for (auto& c : M[digits[2] - '0']) {
                        string x = "";
                        x += a; x += b; x += c;
                        sol.push_back(x);
                    }
                }
            }
        }
        if (len == 4) {
            for (auto& a : M[digits[0] - '0']) {
                for (auto& b : M[digits[1] - '0']) {
                    for (auto& c : M[digits[2] - '0']) {
                        for (auto& d : M[digits[3] - '0']) {
                            string x = "";
                            x += a; x += b; x += c; x += d;
                            sol.push_back(x);
                        }
                    }
                }
            }
        }
        return sol;
    }
};
