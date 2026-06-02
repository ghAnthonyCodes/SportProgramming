class Solution {
public:
    /*  1 digit good numbers: 2, 5, 6, 9 = 4
        2 digit good numbers:
            Those that start with (2, 5, 6, 9) * (0, 1, 2, 5, 6, 7, 9) 
            Those that start with (1, 8) * (2, 5, 6, 9) 
            So D[n] = 2 * D[n-1] + 4 * NOOPS[n - 1]

        // 4123
        // [4 | number of good numbers]
        // [3 | ]
    **/
    std::map<char, char> cmap = { 
        { '0', '0' },
        { '1', '1' },
        { '2', '5' },
        { '5', '2' },
        { '6', '9' }, 
        { '8', '8' },
        { '9', '6' }
    };
    int rotated(int N) {
        
        std::string ns = std::to_string(N);
        for (auto &c : ns) {
            if (c == '3' || c == '4' || c == '7') return 0;
            c = this->cmap[c];
        }
        int answer = std::stoi(ns);
        // printf("f(%d) -> %d\n", N, answer);
        return N != std::stoi(ns);
    }
    int rotatedDigits(int N) {
        int answer = 0;
        for (int n=1; n<=N; n++)
            answer += this->rotated(n);
        return answer;
    }
};
