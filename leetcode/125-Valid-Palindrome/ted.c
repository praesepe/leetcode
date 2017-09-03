bool isPalindrome(char* s) {
    int len = strlen(s);
    
    char *head = s;
    char *tail = s + len - 1;
    
    while (head < tail) {
        if (!isalpha(*head) && !isdigit(*head)) {
            head++;
            continue;
        }
        
        if (!isalpha(*tail) && !isdigit(*tail)) {
            tail--;
            continue;
        }
        
        if (tolower(*head) != tolower(*tail)) return false;
        
        head++;
        tail--;
    }
    
    return true;
}
