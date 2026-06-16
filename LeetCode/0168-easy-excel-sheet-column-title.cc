class Solution {
public:
    string convertToTitle(int N) {
        char LUT[26] = { 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 
            'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y'};
        vector<char> V;
        while (N > 0) {
            V.push_back(LUT[N % 26]);
            if (N % 26 == 0) N = N / 26 - 1;
            else N /= 26;
        }
        ostringstream os;
        for (int i = 0; i < V.size(); i++) {
            os << V[V.size() - i - 1];
        }
        return os.str();
    }
};
