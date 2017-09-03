class Solution {
 public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int area = (C - A) * (D - B) + (G - E) * (H - F);
		int l = std::max(A, E);
		int r = std::min(C, G);
		int t = std::min(D, H);
		int b = std::max(B, F);

		if (r > l && t > b) {
			area -= (r - l) * (t - b);
		}

		return area;
    }
};
