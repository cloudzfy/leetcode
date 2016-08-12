/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
private:
    set<int> s;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        s.insert(val);
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> ans;
        int start = -2, end = -2;
        for (auto it = s.begin(); it != s.end(); it++) {
            if (start == -2) {
                start = *it;
                end = *it;
            } else if (end + 1 == *it) {
                end++;
            } else {
                ans.push_back(Interval(start, end));
                start = *it;
                end = *it;
            }
        }
        ans.push_back(Interval(start, end));
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
