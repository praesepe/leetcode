int myAtoi(char* str) {
    while (*str == ' ') str++;
    
    unsigned int ans = 0;
    unsigned int previous_ans = 0;
    int sign = (*str == '-') ? -1 : 1;
    
    if (*str == '-' || *str == '+') str++;
    
    int previous_max = INT_MAX / 10;
    unsigned int absolute_max = sign>0 ? INT_MAX : INT_MIN*-1;
    for (;isdigit(*str);str++) {
        ans = (previous_ans * 10) + *str - '0';
        if (previous_ans > previous_max || ans < previous_ans || ans >= absolute_max) {
            return sign>0 ? INT_MAX : INT_MIN;
        }
        previous_ans = ans;
    }
    
    return sign * ans;
}
