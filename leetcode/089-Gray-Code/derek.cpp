class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);

        for (int i = 0; i < n; i++) {
            int size = result.size();
            for (int j = size - 1; j >= 0; j--) {
                int num = result[j] + (1 << i);
                result.push_back(num);
            }
        }

        return result;
    }
};
