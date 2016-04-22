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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int now = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].start < now) return false;
            now = intervals[i].end;
        }
        return true;
    }
    static bool cmp(Interval a, Interval b) {
        if (a.start == b.start) return a.end < b.end;
        return a.start < b.start;
    }
};
