class Solution {
public:
    int lengthOfLastWord(string s) {
        int word_length = -1;
        bool ended = true;
        for (auto& c : s) {
            if (c != ' ') {
                if (ended) {
                    word_length = 1;
                    ended = false;
                } else {
                    word_length++;
                }
            }
            else ended = true;
        }
        return word_length;
    }
};
