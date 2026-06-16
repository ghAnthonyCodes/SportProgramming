class Solution {
public:
    bool isPalindrome(string s) {
        ostringstream os;
        for (auto c : s) {
            if (c >= 'A' && c <= 'Z') os << (char)(c + ('a' - 'A'));
            else if (c >= 'a' && c <= 'z') os << c;
            else if (c >= '0' && c <= '9') os << c;
            else continue;
        }
        s = os.str();
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - i - 1]) return false;
        }
        return true;
    }
};
