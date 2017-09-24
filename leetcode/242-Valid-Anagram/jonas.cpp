class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::vector<int> arr(255, 0);

        for (auto c: s) {
            arr[c]++;
        }
        for (auto c: t) {
            arr[c]--;
        }

        for(auto i: arr) {
            if (i != 0) {
                return false;
            }
        }
        return true;
    }
};
