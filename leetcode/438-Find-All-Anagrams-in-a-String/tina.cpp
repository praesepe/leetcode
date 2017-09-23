class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int slen = s.length();
        int plen = p.length();
        
        if (slen == 0 && plen == 0 && slen < plen) return result;
        
        int i, j, count;
        unordered_map<char, int> smap;
        
        for (i = 0;i < plen; i++) {
            smap[p[i]]++;
        }
        
        i = j = 0;
        count = plen;
        
        while (j < slen) {
            if (smap[s[j]] > 0) {
                count--;
            }
            smap[s[j]]--;
            j++;
            
            if (count == 0) {
                result.push_back(i);
            }
            
            if (j - i == plen) {
                if (smap[s[i]] >= 0) {
                    count++;
                }
                smap[s[i]]++;
                i++;
            }
        }
        
        return result;
    }
};
