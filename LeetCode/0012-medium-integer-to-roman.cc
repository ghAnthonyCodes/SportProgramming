class Solution {
public:
    string intToRoman(int num) {
        string sol = "";
        while (num > 0) {
            auto n = to_string(num);
            if (n[0] != '4' && n[0] != '9') {
                if (num >= 1000) {
                    num -= 1000;
                    sol += 'M';
                } else if (num >= 500) {
                    num -= 500;
                    sol += 'D';
                } else if (num >= 100) {
                    num -= 100;
                    sol += 'C';
                } else if (num >= 50) {
                    num -= 50;
                    sol += 'L';
                }
                else if (num >= 10) {
                    num -= 10;
                    sol += 'X';
                } else if (num >= 5) {
                    num -= 5;
                    sol += 'V';
                } else {
                    num--;
                    sol += 'I';
                }
            } else if (n[0] == '9') {
                if (num >= 900) { num -= 900; sol += "CM"; }
                else if (num >= 90) { num -= 90; sol += "XC"; }
                else if (num >= 9) { num -= 9; sol += "IX"; }
            } else if (n[0] == '4') {
                if (num >= 400) { num -= 400; sol += "CD"; }
                else if (num >= 40) { num -= 40; sol += "XL"; }
                else if (num >= 4) { num -= 4; sol += "IV"; }
            }
        }
        return sol;
    }
};
