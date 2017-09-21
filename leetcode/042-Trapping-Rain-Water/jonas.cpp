class Solution {
public:
    int trap(std::vector<int>& height) {
        int lmax = 0;
        int rmax = 0;
        int l = 0;
        int r = height.size() - 1;
        int trapped = 0;

        while (l < r) {
            lmax = std::max(height[l], lmax);
            rmax = std::max(height[r], rmax);

            if (lmax < rmax) {
                l += 1;
                trapped += std::max(0, lmax - height[l]);
            } else {
                r -= 1;
                trapped += std::max(0, rmax - height[r]);
            }
        }
        return trapped;
    }
};
