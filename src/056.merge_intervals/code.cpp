/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if (intervals.size() == 0) return ans;
        sort(intervals.begin(), intervals.end(), cmp);
        int start = intervals[0].start;
        int end = intervals[0].end;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start <= end) {
                end = max(end, intervals[i].end);
            } else {
                Interval myans(start, end);
                ans.push_back(myans);
                start = intervals[i].start;
                end = intervals[i].end;
            }
        }
        Interval myans(start, end);
        ans.push_back(myans);
        return ans;
    }
    static bool cmp(Interval a, Interval b) {
        if (a.start == b.start) {
            return a.end < b.end;
        }
        return a.start < b.start;
    }
};
