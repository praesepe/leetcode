bool myfunction (Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (intervals.size() == 0) {
            return result;
        }

        sort(intervals.begin(), intervals.end(), myfunction);

        Interval curr = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            // -----
            //        -----
            if (curr.end < intervals[i].start) {
                result.push_back(curr);
                curr = intervals[i];
            // ----------
            //     -----
            } else if (curr.end > intervals[i].end) {

            // -----
            //    -----
            } else {
                curr.end = intervals[i].end;
            }

        }
        result.push_back(curr);

        return result;
    }
};
