class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st;

        for (auto num: nums) {
            st.insert(num);
            if (st.size() > 3) {
                st.erase(st.begin());
            }
        }

        if (st.size() < 3) {
            return *st.rbegin();
        }

        return *st.begin();
    }
};

