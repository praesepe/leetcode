class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        for (int i = 1; i < n; i++) {
            left[i] = max(left[i-1], height[i-1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i+1], height[i+1]);
        }

        int sum = 0;
        for (int i = 1; i < n - 1; i++) {
            int minH = min(left[i], right[i]);
            if (minH > height[i]) {
                sum += minH - height[i];
            }
        }

        return sum;
    }
};

