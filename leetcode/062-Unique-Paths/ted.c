int uniquePaths(int m, int n) {
    int max = (m > n) ? m : n;
    int min = (m > n) ? n : m;
    long numerator = 1;
    
    for (int i=1;i<min;i++) {
        numerator = (numerator * (max + min - 1 - i)) / i;
    }
    
    return numerator;
}
