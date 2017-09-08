class Solution {
public:
    static bool compareStart(const Interval &lhs, const Interval &rhs) {
        return (lhs.start < rhs.start);
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (0 == intervals.size()) {
            return result;
        }
        
        sort(intervals.begin(), intervals.end(), compareStart);
        Interval interval = intervals[0];
        for (int i = 1;i < intervals.size(); i++) {
            if (interval.end >= intervals[i].start) {
                interval.end = max(interval.end, intervals[i].end);
            } else {
                result.push_back(interval);
                interval = intervals[i];
            }
        }
        result.push_back(interval);
        
        return result;
    }
};
