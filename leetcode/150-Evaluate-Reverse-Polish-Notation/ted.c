int minusHandler(int a, int b) {
    return b - a;
}

int addHandler(int a, int b) {
    return b + a;
}

int multiplyHandler(int a, int b) {
    return b * a;
}

int divideHandler(int a, int b) {
    return b / a;
}

int parseInt(char *token) {
    int sign = (*token == '-') ? -1 : 1;
    int sum = 0;
    
    if (*token == '-') {
        token++;
    }
    
    while (*token != NULL) {
        sum *= 10;
        sum += *token++ - 48;
    }
    
    return sign * sum;
}

int evalRPN(char** tokens, int tokensSize) {
    int stack_size = 0;
    int stack[tokensSize];
    int (*handlers[256])(int, int) = {NULL};
    
    handlers['-'] = &minusHandler;
    handlers['+'] = &addHandler;
    handlers['*'] = &multiplyHandler;
    handlers['/'] = &divideHandler;
    
    for (int i=0;i<tokensSize;i++) {
        if (strlen(tokens[i]) == 1 && handlers[*(tokens[i])]) {
            stack[stack_size-2] = (*handlers[*(tokens[i])])(stack[stack_size-1], stack[stack_size-2]);
            stack_size--;
        } else {
            stack[stack_size++] = parseInt(tokens[i]);
        }
    }
    
    return stack[0];
}
