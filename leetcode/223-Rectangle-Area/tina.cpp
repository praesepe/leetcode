class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (C - A) * (D - B) + (G - E) * (H - F);
        int l = max(A, E);
        int r = min(C, G);
        int t = min(D, H);
        int b = max(B, F);
        
        if (l < r && b < t) {
            area -= (r - l) * (t - b);
        }
        
        return area;
    }
};
