/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define LEADNODE 0
#define LEFTNODE 1
#define RIGHTNODE 2
#define FULLNODE 3
#define CODESIZE (sizeof(char) + sizeof(int))

int countNodes(struct TreeNode *);
void dfsSerialize(struct TreeNode *, char *, int *);
struct TreeNode *dfsDeserialize(char **, struct TreeNode *, int *);

/** Encodes a tree to a single string. */
char* serialize(struct TreeNode* root) {
    int numNodes = countNodes(root);
    char *codes = malloc(sizeof(int) + (numNodes * CODESIZE));
    
    *((int *) codes) = numNodes;
    int nodeCount = 0;
    dfsSerialize(root, codes + sizeof(int), &nodeCount);
    
    return codes;
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    if (!data) return NULL;
    
    int numberNodes = *((int *) data);
    data += sizeof(int);
    
    if (numberNodes == 0) return NULL;
    
    int nodeCount = 0;
    struct TreeNode *nodes = calloc(numberNodes, sizeof(struct TreeNode));
    
    return dfsDeserialize(&data, nodes, &nodeCount);
}

struct TreeNode* dfsDeserialize(char **data, struct TreeNode *nodes, int *nodeCount) {
    char type = **data;
    int value = *((int *)((*data) + sizeof(char)));
    *data += CODESIZE;
    
    int nodeIdx = (*nodeCount)++;
    nodes[nodeIdx].val = value;
    if (type == FULLNODE || type == LEFTNODE) {
        nodes[nodeIdx].left = dfsDeserialize(data, nodes, nodeCount);
    }
    
    if (type == FULLNODE || type == RIGHTNODE) {
        nodes[nodeIdx].right = dfsDeserialize(data, nodes, nodeCount);
    }
    
    return nodes + nodeIdx;
}

void dfsSerialize(struct TreeNode *node, char *codes, int *nodeCount) {
    if (!node) return;
    
    char type=0;
    if (node->left) type += LEFTNODE;
    if (node->right) type += RIGHTNODE;
    
    memcpy(codes + (CODESIZE * (*nodeCount)), &type, sizeof(char));
    memcpy(codes + (CODESIZE * (*nodeCount)) + sizeof(char), &(node->val), sizeof(int));
    (*nodeCount)++;
    
    dfsSerialize(node->left, codes, nodeCount);
    dfsSerialize(node->right, codes, nodeCount);
}

int countNodes(struct TreeNode *node) {
    if (!node) return 0;
    
    return 1 + countNodes(node->left) + countNodes(node->right);
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);
