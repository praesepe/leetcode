#include <unordered_map>
#include <stack>
#include <vector>
#include <list>

using namespace std;

class Solution {
private:
	void findAllPids(unordered_map<int, list<int>> &graph, vector<int> &result, int kill) {
		result.push_back(kill);
		for (const auto target : graph[kill]) {
			findAllPids(graph, result, target);
		}
	}
public:
	vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
		vector<int> result;
		unordered_map<int, list<int>> graph;

		// setup graph
		for (size_t i = 0; i < ppid.size(); i++) {
			unordered_map<int, list<int>>::iterator itr = graph.find(ppid[i]);
			if (itr == graph.end()) {
				graph[ppid[i]] = list<int>();
			}
			graph[ppid[i]].push_front(pid[i]);
		}

		// run
		findAllPids(graph, result, kill);

		return result;
	}
};
