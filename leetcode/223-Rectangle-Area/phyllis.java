class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	int rect1_l = C - A, rect1_w = D - B;
        int rect2_l = G - E, rect2_w = H - F;
        long area = (rect1_l * rect1_w) + (rect2_l * rect2_w);
        
        long max_x = Math.max(C,G);
        long max_y = Math.max(D,H);
        int min_x = Math.min(A,E);
        int min_y = Math.min(B,F);
        long range_l = max_x - min_x;
        long range_w = max_y - min_y;
        
        if((range_l < rect1_l + rect2_l) && (range_w < rect1_w + rect2_w))
        {
            area -= (rect1_l + rect2_l - range_l) * (rect1_w + rect2_w - range_w);
        }
            
        return (int)area;        
    }
}

