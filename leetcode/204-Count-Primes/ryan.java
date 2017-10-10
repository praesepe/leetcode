class Solution {
    public int countPrimes(int n) {
        if (n < 3) {
            return 0;
        }
        boolean[] notPrime = new boolean[n];
        int cnt = 1;
        for (int i = 3; i < n; i += 2) {
            if (!notPrime[i]) {
                cnt++;
                for (int j = 2; j * i < n; j++) {
                    notPrime[j * i] = true;
                }
            }
        }
        return cnt;
    }
}