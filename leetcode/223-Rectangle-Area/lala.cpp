#include <cstdint>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool check_overlap(int bl1, int tr1, int bl2, int tr2) {
        uint64_t min_value = min(bl1, bl2);
        uint64_t max_value = max(tr1, tr2);

        return (max_value - min_value) <= uint64_t((tr1 - bl1) + (tr2 - bl2));
    }
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        uint64_t area_1 = (C - A) * (D - B);
        uint64_t area_2 = (G - E) * (H - F);

        uint64_t overlap = this->check_overlap(A, C, E, G) && this->check_overlap(B, D, F, H) ?
            (max(E, A) - min(G, C)) * (max(F, B) - min(H, D)) :
            0;
        return int(area_1 + area_2 - overlap);
    }
};
