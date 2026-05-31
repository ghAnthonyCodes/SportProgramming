class Solution {
public:
    int romanToInt(string s) {
        int sol = 0;
        char last = '0';
        map<char, int> M = {
            { 'I', 1 },
            { 'V', 5 }, 
            { 'X', 10 }, 
            { 'L', 50 }, 
            { 'C', 100 }, 
            { 'D', 500 }, 
            { 'M', 1000 }
        };
        for (auto& c : s) {
            sol += M[c];
            if (last == 'I' && (c == 'V' || c == 'X')) sol -= 2;
            if (last == 'X' && (c == 'L' || c == 'C')) sol -= 20;
            if (last == 'C' && (c == 'D' || c == 'M')) sol -= 200;
            last = c;
        }
        return sol;
    }
};
