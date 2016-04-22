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
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        priority_queue<int, vector<int>, greater<int>> q;
        q.push(0);
        for (int i = 0; i < intervals.size(); i++) {
            int now = q.top();
            if (intervals[i].start >= now) q.pop();
            q.push(intervals[i].end);
        }
        return min(q.size(), intervals.size());
    }
    static bool cmp(Interval a, Interval b) {
        if (a.start == b.start) return a.end < b.end;
        return a.start < b.start;
    }
};
