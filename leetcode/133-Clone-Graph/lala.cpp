#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Definition for undirected graph.
 */
struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
private:
	UndirectedGraphNode* clone(
		UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*,
		UndirectedGraphNode*> &visted) {
		if (!node) {
			return NULL;
		}

		// lookup table
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>::iterator itr = visted.find(node);
		if (itr != visted.end()) {
			return itr->second;
		}

		// new node
		UndirectedGraphNode* result = new UndirectedGraphNode(node->label);
		visted.insert(make_pair(node, result));
		for (size_t i = 0; i < node->neighbors.size(); i++) {
			result->neighbors.push_back(this->clone(node->neighbors[i], visted));
		}
		return result;
	}
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visted;

		return this->clone(node, visted);
	}
};
