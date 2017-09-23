class Solution {
public:    
    bool isAnagramSorted(string s, string t) {
        if (s.length() != t.length()) return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return (s == t);
    }
    
    bool isAnagramCountCharacters(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> set;
        int i;
        
        for (i = 0;i < s.length(); i++) {
            set[s[i] - 'a']++;
        }
        
        for (i = 0;i < t.length(); i++) {
            if (set[t[i] - 'a'] <= 0) {
                return false;
            }
            set[t[i] - 'a']--;
        }
        
        return true;
    }
};
