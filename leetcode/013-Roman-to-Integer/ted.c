int romanToInt(char* s) {
    int values[256];
    
    values['I'] = 1;
    values['V'] = 5;
    values['X'] = 10;
    values['L'] = 50;
    values['C'] = 100;
    values['D'] = 500;
    values['M'] = 1000;
    
    int answer = 0;
    
    while (*s != NULL) {
        int sign = 1;
        if (*(s+1) != NULL && values[*s] < values[*(s+1)]) {
            sign = -1;
        }
        
        answer += sign*values[*s];
        s++;
    }
    
    return answer;
}
