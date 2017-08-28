char* addBinary(char* a, char* b) {
    int a_len = strlen(a);
    int b_len = strlen(b);
    int aa, bb, cc;
    int sum_len = (a_len > b_len ? a_len : b_len) + 1;
    
    char *sum = calloc(sum_len + 1, sizeof(char));
    
    cc = 0;
    while (a_len > 0 || b_len > 0) {
        aa = a_len > 0 ? a[--a_len] - '0' : 0;
        bb = b_len > 0 ? b[--b_len] - '0' : 0;
        sum[--sum_len] = '0' + ((aa + bb + cc) % 2);
        cc = (aa + bb + cc) / 2;
    }
    
    if (cc) sum[--sum_len] = '1';
    
    if (sum_len > 0) {
        sum_len = strlen(sum+1);
        memmove(sum, sum + 1, sum_len);
        sum[sum_len] = 0;
    }
    
    return sum;
}
