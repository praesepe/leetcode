bool isValid(char* s) {
    char mappings[256] = {0};
    
    mappings[')'] = '(';
    mappings['}'] = '{';
    mappings[']'] = '[';
    
    int stack_size=0;
    char *start = s;
    
    while (*s != NULL) {
        if (mappings[*s]) {
            if (stack_size <= 0 || mappings[*s] != *(start + --stack_size)) {
                return false;
            }
        } else {
            *(start + stack_size++) = *s;
        }
        
        s++;
    }
    
    return stack_size == 0;
}
