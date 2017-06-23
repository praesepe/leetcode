class Solution {
public:
    bool isValid(string s) {

        map<char, char> mp = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };

        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            if (mp.find(s[i]) != mp.end()) {
                st.push(s[i]);
                continue;
            }

            if (st.empty() || mp[st.top()] != s[i]) {
                return false;
            }
            st.pop();
        }

        return st.empty();
    }
};
