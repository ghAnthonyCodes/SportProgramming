class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cm[26];
        memset(cm, 0, 26);
        for (auto& c : text) cm[c - 'a']++;
        int sol = 0;
        sol = cm['b' - 'a'];
        sol = min(cm['a' - 'a'], sol);
        sol = min(cm['l' - 'a'] / 2, sol);
        sol = min(cm['o' - 'a'] / 2, sol);
        sol = min(cm['n' - 'a'], sol);
        return sol;
    }
};
