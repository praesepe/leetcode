#include <unordered_map>
#include <queue>
#include <vector>
#include <list>

using namespace std;

class Solution {
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
		queue<int> run_queue;
		run_queue.push(kill);
		while (!run_queue.empty()) {
			int id = run_queue.front();
			run_queue.pop();
			result.push_back(id);

			for (const auto target : graph[id]) {
				run_queue.push(target);
			}
		}


		return result;
	}
};
