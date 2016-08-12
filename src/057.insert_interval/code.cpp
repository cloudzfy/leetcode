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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        if (intervals.size() == 0) {
            ans.push_back(newInterval);
            return ans;
        }
        bool isStarted = false;
        bool isEnded = false;
        int start, end;
        if (newInterval.start <= intervals[0].start) {
            isStarted = true;
            start = newInterval.start;
        }
        if (newInterval.end < intervals[0].start) {
            isEnded = true;
            end = newInterval.end;
            ans.push_back(newInterval);
        }
        for (int i = 0; i < intervals.size(); i++) {
            if (!isStarted) {
                if (newInterval.start <= intervals[i].start) {
                    isStarted = true;
                    start = newInterval.start;
                } else if (newInterval.start <= intervals[i].end) {
                    isStarted = true;
                    start = intervals[i].start;
                }
            }
            if (isStarted && !isEnded) {
                if (newInterval.end < intervals[i].start) {
                    isEnded = true;
                    end = newInterval.end;
                    Interval myans(start, end);
                    ans.push_back(myans);
                } else if (newInterval.end <= intervals[i].end) {
                    isEnded = true;
                    end = intervals[i].end;
                    Interval myans(start, end);
                    ans.push_back(myans);
                    continue;
                }
            }
            if (!isStarted && !isEnded) ans.push_back(intervals[i]);
            if (isStarted && isEnded) ans.push_back(intervals[i]);
        }
        if (!isStarted) {
            ans.push_back(newInterval);
        } else if (isStarted && !isEnded) {
            end = newInterval.end;
            Interval myans(start, end);
            ans.push_back(myans);
        }
        return ans;
    }
};
