class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> map = {{'(', ')'},
                               {'[', ']'},
                               {'{', '}'}};

        for (char c: s) {
            if (map.find(c) != map.end()) {
                st.push(c);
                continue;
            }

            if (st.empty()) {
                return false;
            }

            char t = st.top();
            if (c != map[t]) {
                return false;
            }
            st.pop();
        }

        if (!st.empty()) {
            return false;
        }

        return true;
    }
};
