class Solution {
public:
    int guessNumber(int n) {
        int lo = 1; int hi = n; int m;
        while(1) {
            m = lo + (hi - lo) / 2;
            int result = guess(m);
            if (result == 0) return m;
            if (result == -1) hi = m;
            else lo = lo == m ? m + 1 : m;
        }
        return false;
    }
};
