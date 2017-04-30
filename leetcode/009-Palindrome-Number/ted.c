bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    
    if (x < 10) {
        return true;
    }
    
    int x_div_10 = x / 10;
    int x_mod_10, x_div_base;
    int base = 10;
    
    while (base <= x_div_10) {
        base *= 10;
    }
    
    while (base >= 10) {
        x_div_base = x / base;
        x_mod_10 = x % 10;
        if (x_div_base != x_mod_10) {
            return false;
        }
        
        x -= (x_div_base * base + x_mod_10);
        x /= 10;
        base /= 100;
    }
    
    return true;
}
