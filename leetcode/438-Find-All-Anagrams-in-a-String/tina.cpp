class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int slen = s.length();
        int plen = p.length();
        
        if (slen < plen) return result;
        
        vector<int> primes = {
            2, 3, 5, 7, 11, 13,
            17, 19, 23, 29, 31,
            37, 41, 43, 47, 53, 
            59, 61, 67, 71, 73,
            79, 83, 89, 91, 97
        };
        
        int i, j, tmp, sum;
        
        sum = 0;
        for (i = 0;i < plen; i++) {
            sum += primes[p[i] - 'a'];
        }
        
        tmp = 0;
        for (i = 0;i < plen; i++) {
            tmp += primes[s[i] - 'a'];
        }
        if (sum == tmp) result.push_back(0);
        
        for (j = 1;j <= slen - plen; j++) {
            tmp -= primes[s[j - 1] - 'a'];
            tmp += primes[s[j + plen - 1] - 'a'];
            if (sum == tmp) result.push_back(j);
        }
        
        return result;
    }
};
