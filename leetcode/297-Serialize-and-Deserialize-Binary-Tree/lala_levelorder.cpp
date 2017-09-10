#include <vector>
#include <string>
#include <queue>
#include <sstream>

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
	vector<TreeNode*> parse_to_vector(string data) {
		vector<TreeNode*> result;

		size_t previous = 0;
		while (true) {
			size_t current = data.find(",", previous);
			if (current == string::npos) break;

			string entry = data.substr(previous, current - previous);
			if (entry != "null") {
				result.push_back(new TreeNode(stoi(entry)));
			} else {
				result.push_back(NULL);
			}

			previous = current + 1;
		}

		return result;
	}
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		queue<TreeNode*> q;

		stringstream ss;
		q.push(root);
		while (!q.empty()) {
			TreeNode* n = q.front();
			if (!n) {
				ss << "null,";
			} else {
				ss << n->val << ",";
				q.push(n->left);
				q.push(n->right);
			}

			q.pop();
		}

		return ss.str();
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		vector<TreeNode*> heap = this->parse_to_vector(data);

		TreeNode *root = heap[0];
		size_t count = 0, move = 0;
		for (size_t i = 1; i < heap.size(); i++) {
			TreeNode* walker = heap[move];
			while (walker == nullptr) {
				walker = heap[++move];
				if (move >= heap.size()) return root;
			}

			if (count % 2 == 0) {
				walker->left = heap[i];
			} else {
				walker->right = heap[i];
				move++;
			}
			count++;
		}

		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
