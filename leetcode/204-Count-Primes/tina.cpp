class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        
        vector<bool> isPrime(n, true);
        int count = 0;
        
        for (int i = 2;i < n; i++) {
            if (isPrime[i]) {
                count++;
                
                if (i < sqrt(n)) {
                    for (int j = 2;j * i < n; j++) {
                        isPrime[j * i] = false;
                    }
                }
            }
        }
        
        return count;
    }
};
