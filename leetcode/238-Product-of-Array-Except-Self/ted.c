/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *ret = calloc(numsSize, sizeof(int));
    for (int i=0; i<numsSize; i++) {
        ret[i] = 1;
    }
    *returnSize = numsSize;
    
    int fromHead=1, fromTail=1;
    
    for (int i=0; i<numsSize; i++) {
        int reverseI = numsSize - 1 - i;
        ret[i] *= fromHead;
        ret[reverseI] *= fromTail;        
        fromHead *= nums[i];
        fromTail *= nums[reverseI];
    }
    
    return ret;
}
