typedef vector<int> vi;

class Solution {
public:
    int maxArea(vi& height) {
        int N = (int)height.size();
        int i = 0; int j = N - 1;
        int area = 0;
        while (i != j) {
            // i is limiting factor
            if (height[i] < height[j]) {
                area = max(area, height[i] * (j - i));
                i++;
            } else {
                area = max(area, height[j] * (j - i));
                j--;
            }
        }
        return area;
    }
};
