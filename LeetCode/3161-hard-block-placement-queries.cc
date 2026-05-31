typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vii;

struct Triangle {
    int a;
    int b;
    int c;
    bool bypass;
};

class SegTree {
    vector<Triangle> T;
    int N;
public:

    void build(int N) {
        this->N = N;
        this->T = vector<Triangle>(2 * N);
        T[N] = Triangle(0, 0, 0, 1);
        for (int n=N + 1; n < 2*N; n++) T[n] = Triangle(1, 1, 1, 1);
        for (int n=N - 1; n>0; n--) this->_update(n);     
    }

    void insert(int idx) {
        int start = N + idx;
        T[start].c = 0;
        T[start].bypass = false;
        start = start >> 1;
        while (start > 0) {
            this->_update(start);
            start = start >> 1;
        }
    }

    bool query(int idx, int sz) {
        int n = N + idx;
        int r_idx = n;

        // Find starting r_idx
        while ((r_idx & 1) == 1 && r_idx > 1)
            r_idx = r_idx >> 1;

        // Check if right index is a power of 2
        int set_bits = 0;
        int tmp = r_idx;
        while (tmp > 0) {
            if (tmp & 1) set_bits++;
            tmp >>= 1;
        }
        if (set_bits == 1)
            return sz <= T[r_idx].a;

        Triangle Q = T[r_idx];
        int l_idx = (r_idx >> 1) - 1;
        while(1) {

            // Find what to merge with
            while ((l_idx & 1) == 1 && l_idx > 1)
                l_idx = l_idx >> 1;
            this->_merge(Q, l_idx);

            // If we just merged a power of 2, we are done
            set_bits = 0;
            tmp = l_idx;
            while (tmp > 0) {
                if (tmp & 1) set_bits++;
                tmp >>= 1;
            }
            if (set_bits == 1)
                break;

            l_idx = (l_idx >> 1) - 1;   
        }

        return sz <= Q.a;
    }

    void _merge(Triangle &Q, int l) {
        Triangle R = Q;
        Q.b = T[l].bypass ? T[l].b + R.b : T[l].b;
        Q.c = R.bypass ? T[l].c + R.c : R.c;
        Q.a = max(Q.b, Q.c);
        Q.a = max(Q.a, T[l].a);
        Q.a = max(Q.a, R.a);
        Q.a = max(Q.a, T[l].c + R.b);
        Q.bypass = T[l].bypass && R.bypass;
    }

    void _update(int n) {
        int l = n << 1;
        int r = l | 1;
        // Correct
        T[n].b = T[l].bypass ? T[l].b + T[r].b : T[l].b;
        T[n].c = T[r].bypass ? T[l].c + T[r].c : T[r].c;
        T[n].a = max(T[n].b, T[n].c);
        T[n].a = max(T[n].a, T[l].a);
        T[n].a = max(T[n].a, T[r].a);
        T[n].a = max(T[n].a, T[l].c + T[r].b);
        T[n].bypass = T[l].bypass && T[r].bypass;
    }

    void print(void) {
        for (int n=2 * N-1; n>0; n--)         
            printf("    T[%2d] = <%2d %2d %2d | %b>\n", n, T[n].b, T[n].a, T[n].c, T[n].bypass);
    }

    
};

class Solution {
public:

    vb getResults(vii& queries) {
        int max_query = 0;
        for (auto& query : queries) {
            max_query = max(max_query, query[1]);
        }
        int N = 1; 
        while (N < max_query + 1)
            N *= 2; // 262144;
      
        SegTree segtree = SegTree();
        segtree.build(N);

        vb answer;

        for (auto& query : queries) {
            if (query[0] == 1) {
                segtree.insert(query[1]);
            }
            else {
                bool result = segtree.query(query[1], query[2]);
                answer.push_back(result);
            }
        }
        return answer;
    }
};
