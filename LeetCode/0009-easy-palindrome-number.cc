class Solution {
public:
    bool isPalindrome(int x) {
        auto xs = std::to_string(x);
        int s = xs.size();
        int l = s/2;
        for (int i=0; i<l; i++) {
            if (xs[i] != xs[s - i - 1])
                return false;
        }
        return true;
    }
};
