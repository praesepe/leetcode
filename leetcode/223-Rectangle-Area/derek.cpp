class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int areaSqureA = (C - A) * (D - B);
        int areaSqureB = (G - E) * (H - F);

        int left = max(A, E);
        int right = min(C, G);
        int bottom = max(B, F);
        int top = min(D, H);

        // overlap
        int overlap = 0;
        if (right > left && top > bottom) {
            overlap = (right - left) * (top - bottom);
        }

        return areaSqureA + areaSqureB - overlap;
    }
};
