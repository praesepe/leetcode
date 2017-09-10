#include <sstream>
#include <string>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
    void serialize_preorder(stringstream &ss, TreeNode* root) {
        if (!root) {
            ss << " null" ;
            return;
        }

        ss << " " << root->val;
        serialize_preorder(ss, root->left);
        serialize_preorder(ss, root->right);
    }

    TreeNode* deserialize_preorder(stringstream &ss) {
        string chunk;
        if (!(ss >> chunk)) return NULL;
        if (chunk == "null") return NULL;

        TreeNode* root = new TreeNode(stoi(chunk));
        root->left = deserialize_preorder(ss);
        root->right = deserialize_preorder(ss);

        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        serialize_preorder(ss, root);

        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);

        return deserialize_preorder(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
