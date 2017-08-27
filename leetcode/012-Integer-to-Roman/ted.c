char* intToRoman(int num) {
    char *buffer = calloc(16, 1);
    int base[4] = {1000, 100, 10, 1};
    char charOne[4] = {'M', 'C', 'X', 'I'};
    char charFive[4] = {0, 'D', 'L', 'V'};
    
    int n;
    int idx = 0;
    for (int i=0;i<4;i++) {
        n = num / base[i];
        num = num % base[i];
        switch(n) {
            case 1:
            case 2:
            case 3:
            for (int j=0;j<n;j++) {
                buffer[idx++] = charOne[i];
            }
            break;
            case 4:
            buffer[idx++] = charOne[i];
            case 5:
            buffer[idx++] = charFive[i];
            break;
            case 6:
            case 7:
            case 8:
            buffer[idx++] = charFive[i];
            for (int j=0;j<n-5;j++) {
                buffer[idx++] = charOne[i];
            }
            break;
            case 9:
            buffer[idx++] = charOne[i];
            buffer[idx++] = charOne[i-1];
            default:
            break;
        }
    }
    
    return buffer;
}
