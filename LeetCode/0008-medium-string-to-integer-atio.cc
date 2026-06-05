class Solution {
public:
    int myAtoi(string s) {
        bool has_whitespace = false;
        bool is_negative = false;
        int ptr = 0;

        // Handle leading whitespace
        while (ptr < s.size()) {
            if (s[ptr] == ' ') {
                ptr++;
                has_whitespace = true;
            }
            else {
                break;
            }
        }

        // Handle signedness
        if (s[ptr] == '-') {
            is_negative = true;
            ptr++;
        } else if (s[ptr] == '+') {
            ptr++;
        }

        // Skip leading zeros
        while (s[ptr] == '0') ptr++;

        // Read in until a non-digit character is read or end of str
        long long sol = 0;
        long long m = 10;
        while (ptr < s.size()) {
            char c = s[ptr];
            if (c < '0' || c > '9') break;
            long long digit = c - '0';
            sol = m * sol + digit;
            if (is_negative && sol >= 2147483648)
                return -2147483648;
            else if (!is_negative && sol >= 2147483647)
                return 2147483647;
            ptr++;
        }

        if (is_negative) {
            int sol_int = sol;
            return -sol_int;
        }
        return (int)sol;
    }
};
