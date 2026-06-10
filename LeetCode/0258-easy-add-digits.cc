class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int next = num;
            num = 0;
            while (next > 0) {
                num += next % 10;
                next /= 10;
            }
        }
        return num;
    }
};
