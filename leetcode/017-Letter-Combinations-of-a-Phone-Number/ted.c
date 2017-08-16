/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    const char *map[] = {
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    char **answer;
    int len = strlen(digits);
    int *counts = calloc(len, sizeof(int));
    int *maxCounts = calloc(len, sizeof(int));
    int c = 0;
    
    if (len == 0) {
        *returnSize = 0;
        return answer;
    }
    
    *returnSize = 1;
    for (int i=0; i<len; i++) {
        digits[i] -= 50;
        maxCounts[i] = strlen(map[digits[i]]);
        *returnSize *= maxCounts[i];
    }
    
    answer = calloc(*returnSize, sizeof(char *));
    for (int i=0; i<*returnSize; ++i) {
        answer[i] = calloc(len+1, sizeof(char));
    }
    
    while (c < *returnSize) {
        for (int i=0; i<len; i++) {
            answer[c][i] = map[digits[i]][counts[i]];
        }
        
        counts[len-1]++;
        
        for (int i=len-1;i>0;i--) {
            if (counts[i] != maxCounts[i]) break;
            
            counts[i] = 0;
            counts[i-1]++;
        }
        
        c++;
    }
    
    return answer;
}
