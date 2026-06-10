typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    vvi rotateGrid(vvi& G, int k) {
        int M = G.size();
        int N = G[0].size();
        int layers = std::min(M, N) / 2;
        vvi A = vvi(M, vi(N));
        for (int layer = 0; layer < layers; layer++) {
            int layer_height = (M - 2 * layer);
            int layer_width = (N - 2 * layer);
            // printf("Layer: %d, Width: %d, Height: %d\n", layer, layer_width, layer_height);
            // Read in the layer
            int r = layer;
            int c = layer;
            int layer_size = 2 * layer_height + 2 * (layer_width - 2);

            // printf("Layer[%d] = { ", layer);
            char direction = 'd';
            int layer_ptr = 0;
            vi layer_ints = vi(layer_size);
            vi shift_ints = vi(layer_size);
            int mod_k = k % layer_size;
            while (layer_ptr < layer_size) {
                layer_ints[layer_ptr] = G[r][c];
                // printf(" %d ", G[r][c]);
                layer_ptr++;
                // go to next r, c
                if (direction == 'd') {
                    if (r == M - layer - 1) {
                        direction = 'r';
                        c += 1;
                    } else {
                        r += 1;
                    }
                } else if (direction == 'r') {
                    if (c == N - layer - 1) {
                        direction = 'u';
                        r -= 1;
                    } else {
                        c += 1;
                    }
                } else if (direction == 'u') {
                    if (r == layer) {
                        direction = 'l';
                        c -= 1;
                    } else {
                        r -= 1;
                    }
                } else if (direction == 'l') {
                    if (c == layer) {
                        direction = 'd';
                        r += 1;
                    } else {
                        c -= 1;
                    }
                }
            }

            // printf("}\n");

            // Apply shift
            int ptr = mod_k;
            for (int i=0; i<layer_size; i++) {
                shift_ints[ptr++] = layer_ints[i];
                if (ptr == layer_size)
                    ptr = 0;
            }

            // Lay down new anwer
            // printf("Shifted Layer[%d] = { ", layer);
            layer_ptr = 0;
            r = c = layer;
            direction = 'd';
            while (layer_ptr < layer_size) {
                //layer_ints[layer_ptr] = G[r][c];
                A[r][c] = shift_ints[layer_ptr];

                // printf(" %d ", A[r][c]);
                layer_ptr++;
                // go to next r, c
                if (direction == 'd') {
                    if (r == M - layer - 1) {
                        direction = 'r';
                        c += 1;
                    } else {
                        r += 1;
                    }
                } else if (direction == 'r') {
                    if (c == N - layer - 1) {
                        direction = 'u';
                        r -= 1;
                    } else {
                        c += 1;
                    }
                } else if (direction == 'u') {
                    if (r == layer) {
                        direction = 'l';
                        c -= 1;
                    } else {
                        r -= 1;
                    }
                } else if (direction == 'l') {
                    if (c == layer) {
                        direction = 'd';
                        r += 1;
                    } else {
                        c -= 1;
                    }
                }
            }
            // printf("}\n");
        }
        return A;
    }
};
