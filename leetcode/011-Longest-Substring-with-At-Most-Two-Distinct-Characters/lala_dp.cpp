#include <string>
#include <stdint.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <stdint.h>

#define MOST_OCCURRENCE 2
using namespace std;

struct DpEntry {
	uint32_t length;
	uint32_t start_index;
	uint32_t last_occurence_count;
	unordered_set<char> occurence_set;
};

class Solution {
private:
	static bool compare(DpEntry d1, DpEntry d2) {
		return d1.length < d2.length;
	}
public:
	static DpEntry solve(string s) {
		DpEntry result;
		result.length = 0;
		result.start_index = 0;

		// initilize table
		vector<DpEntry> dptable(s.size());
		char previous_char;
		for (uint32_t i = 0; i < s.size(); i++) {
			if (i == 0) {
				previous_char = s[i];
				dptable[i].start_index = 0;
				dptable[i].last_occurence_count = 1;
				dptable[i].length = 1;
				dptable[i].occurence_set.insert(s[i]);
			} else {
				dptable[i].last_occurence_count = previous_char == s[i] ?
					dptable[i - 1].last_occurence_count + 1 : 1;
			}

			previous_char = s[i];
		}

		//
		for (string::size_type i = 0; i < s.size(); i++) {
			DpEntry* previous_entry = i == 0 ? &result : &dptable[i - 1];
			DpEntry* current_entry = &dptable[i];
			char previous_char = i == 0 ? '\0' : s[i - 1];
			char current_char = s[i];

			if (previous_entry->occurence_set.size() < MOST_OCCURRENCE) {
				current_entry->length = previous_entry->length + 1;
				current_entry->start_index = previous_entry->start_index;
				current_entry->occurence_set = previous_entry->occurence_set;
				current_entry->occurence_set.insert(current_char);
			} else if (previous_entry->occurence_set.find(current_char) != previous_entry->occurence_set.end()) {
				current_entry->length = previous_entry->length + 1;
				current_entry->start_index = previous_entry->start_index;
				current_entry->occurence_set = previous_entry->occurence_set;
			} else {
				current_entry->length = previous_entry->last_occurence_count + 1;
				current_entry->start_index = i - previous_entry->last_occurence_count;
				current_entry->occurence_set.insert(previous_char);
				current_entry->occurence_set.insert(current_char);
			}

			result = max(result, *current_entry, Solution::compare);
		}

		return result;
	}
};

int main() {
	vector<string> testcases;
	testcases.push_back("");
	testcases.push_back("a");
	testcases.push_back("eceba");
	testcases.push_back("aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa");
	testcases.push_back("abbcccdddd");
	testcases.push_back("abbcccbbbbdddddbbbbbb");
	testcases.push_back("abababababababababababcccccccccccccccccccccccccccccccccccccdd");

	for (vector<string>::size_type i = 0; i < testcases.size(); i++) {
		string testcase = testcases[i];
		DpEntry solution = Solution::solve(testcase);

		cout << testcase
			 << ": "
			 << testcase.substr(solution.start_index, solution.length)
			 << " "
			 << "<"
			 << solution.length
			 << ">"
			 << endl;
	}
	return 0;
}
