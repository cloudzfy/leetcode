/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct cmp {
    bool operator()(const Interval &a, const Interval &b) {
        return a.start < b.start;
    }
};

class SummaryRanges {
    set<Interval, cmp> s;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        auto it = s.lower_bound(Interval(val, val));
        int start = val, end = val;
        if (it != s.begin() && (--it)->end < val - 1) it++;
        while (it != s.end() && it->start <= val + 1 && it->end >= val - 1) {
            start = min(start, it->start);
            end = max(end, it->end);
            it = s.erase(it);
        }
        s.insert(Interval(start, end));
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> ans;
        for (auto it = s.begin(); it != s.end(); it++) {
            ans.push_back(*it);
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
