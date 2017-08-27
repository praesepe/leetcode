int reverse(int x) {
    int mod, sign;
    long long ret=0, xx;
    
    sign = (x < 0) ? -1 : 1;
    xx = (x < 0) ? -x : x;
    
    while (xx>0) {
        mod = xx%10;
        xx = xx/10;
        
        ret *= 10;
        ret += mod;
    }
    
    return (ret > INT_MAX || ret < INT_MIN) ? 0 : sign*ret;
}
