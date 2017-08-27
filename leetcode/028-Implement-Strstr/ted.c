int strStr(char* haystack, char* needle) {
    char *haystack_idx = haystack;
    char *next_idx = NULL;
    char *needle_head = needle;
    char *haystack_head = haystack;
    
    while (*haystack && *needle) {
        if (next_idx == NULL && *haystack == *needle_head && haystack != haystack_idx) {
            next_idx = haystack;
        }
        
        if (*haystack == *needle) {
            if (!haystack_idx) haystack_idx = haystack;
            haystack++;
            needle++;
        } else {
            haystack = next_idx ? next_idx : haystack+1;
            
            haystack_idx = haystack;
            next_idx = NULL;
            
            needle = needle_head;
        }
    }
    
    return *needle ? -1 : haystack_idx - haystack_head;
}
