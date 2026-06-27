class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int right_pos = 0;
        int left_pos = 0;
        for (auto& c : moves) {
            if (c == 'L') right_pos--;
            else right_pos++;

            if (c == 'R') left_pos++;
            else left_pos--;
        }

        return max(abs(left_pos), abs(right_pos));;
    }
};
