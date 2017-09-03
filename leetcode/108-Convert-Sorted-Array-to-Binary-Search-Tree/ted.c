/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize <= 0) {
        return NULL;
    }
    
    int center = numsSize/2;
    struct TreeNode* node = calloc(1, sizeof(struct TreeNode));
    node->val = nums[center];
    node->left = sortedArrayToBST(nums, center);
    node->right = sortedArrayToBST(nums + center + 1, numsSize-center-1);
    
    return node;
}
