int climbStairs(int n) {
    int fn[2] = {1,1};

    if (n <= 1) {
        return 1;
    }
    
    for (int i=2; i<=n; i++) {
        fn[i%2] = fn[0] + fn[1];
    }
    
    return fn[n%2];
}
