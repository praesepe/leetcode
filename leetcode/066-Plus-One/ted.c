int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1;
    int i, digit, *returnDigits;
    
    returnDigits = malloc(sizeof(int)*(digitsSize));
    
    for (i=digitsSize-1;i>=0 && carry;i--) {
        digit = *(digits + i) + carry;
        carry = digit == 10 ? 1 : 0;
        *(returnDigits + i) = digit == 10 ? 0 : digit;
    }
    
    memcpy(returnDigits, digits, sizeof(int)*(i+1));

    *returnSize = digitsSize + carry;
    
    if (carry) {
        returnDigits = realloc(returnDigits, sizeof(int)*(*returnSize));
        *returnDigits = 1;
        *(returnDigits + digitsSize) = 0;
    }
    
    return returnDigits;
}
