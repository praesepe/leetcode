class Solution {
public:
    void reverseWords(string &s) {
        string reversed;
        int n = s.length();

        // i tracks word's begin position
        // j tracks word's ending position
        int j = n;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                j = i;
            } else if (s[i-1] == ' ' || i == 0) {
                if (reversed.size() != 0) {
                    reversed += ' ';
                }
                reversed += s.substr(i, j-i);
            }
        }

        s = reversed;
    }
};
