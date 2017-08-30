#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "null";
        }

        vector<string> tokens = {to_string(root->val)};
        int size = tokens.size();;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            TreeNode* curr = que.front();
            que.pop();

            if (curr->left) {
                que.push(curr->left);
                tokens.push_back(to_string(curr->left->val));
                size = tokens.size();
            } else {
                tokens.push_back("null");
            }

            if (curr->right) {
                que.push(curr->right);
                tokens.push_back(to_string(curr->right->val));
                size = tokens.size();
            } else {
                tokens.push_back("null");
            }
        }

        // concatenate tokens, but remove the trailing null token
        string result;
        for (int i = 0; i < size; i++) {
            if (i != 0) {
                result += ',';
            }
            result += tokens[i];
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // split data to tokens
        vector<string> tokens;
        int i = 0, j = 0, n = data.length();
        while (j < n) {
            while (j < n && data[j] != ',') {
                j++;
            }

            // get a token
            string token = data.substr(i, j - i);
            tokens.push_back(token);

            // next round
            i = j + 1;
            j = i;
        }

		//
		if (tokens[0] == "null") {
			return NULL;
		}

        //
        TreeNode* root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode*> que;
        que.push(root);
        int k = 1;

        while (!que.empty()) {
            TreeNode* curr = que.front();
            que.pop();


            // left child
            if (k == tokens.size()) {
                break;
            }
            if (tokens[k] != "null") {
                curr->left = new TreeNode(stoi(tokens[k]));
                que.push(curr->left);
            }
            k++;

            // right child
            if (k == tokens.size()) {
                break;
            }
            if (tokens[k] != "null") {
                curr->right = new TreeNode(stoi(tokens[k]));
                que.push(curr->right);
            }
            k++;
        }

        return root;
    }
};

int main()
{
	string s = "1,2,3,null,null,4,5";
	cout << s << endl;

    Codec codec;
    TreeNode* root = codec.deserialize(s);

	string r = codec.serialize(root);
	cout << r << endl;

	return 0;
}
