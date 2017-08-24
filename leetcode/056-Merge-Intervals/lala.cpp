#include <vector>
#include <algorithm>

using namespace std;
/*
 * Definition for an interval.
 */
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
private:
	static bool comparator(const Interval &a, const Interval &b) {
		return a.start < b.start;
	}
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.size() == 0) return {};

		// sort by start
		sort(intervals.begin(), intervals.end(), Solution::comparator);

		vector<Interval> result;
		result.push_back(intervals[0]);

		for (const auto current : intervals) {
			Interval &tail = result[result.size() - 1];

			// ---------  tail
			//    ===     current
			if (current.end <= tail.end) {
				continue;
			// ---------     tail
			//    =========  current
			} else if (current.start <= tail.end && tail.end <= current.end) {
				tail.end = current.end;
			// ---------         tail
			//             ====  current
			} else if (current.start > tail.end) {
				result.push_back(current);
			}
		}

		return result;
	}
};
