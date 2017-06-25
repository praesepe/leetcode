typedef struct {
    int *buffer;
    int *mins;
    int idx;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack *minStack = malloc(sizeof(MinStack));
    minStack->buffer   = malloc(sizeof(int) * maxSize);
    minStack->mins     = malloc(sizeof(int) * maxSize);
    minStack->idx      = -1;
    
    return minStack;
}

void minStackPush(MinStack* obj, int x) {
    int min = (obj->idx < 0 || x < obj->mins[obj->idx]) ? x : obj->mins[obj->idx];
    obj->idx++;
    obj->buffer[obj->idx] = x;
    obj->mins[obj->idx] = min;
}

void minStackPop(MinStack* obj) {
    obj->idx--;
}

int minStackTop(MinStack* obj) {
    return obj->buffer[obj->idx];
}

int minStackGetMin(MinStack* obj) {
    return obj->mins[obj->idx];
}

void minStackFree(MinStack* obj) {
    free(obj->buffer);
    free(obj->mins);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */
