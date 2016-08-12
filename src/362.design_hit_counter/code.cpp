class HitCounter {
    vector<int> ts;
    int cur, sum;
public:
    /** Initialize your data structure here. */
    HitCounter() {
        ts.resize(300, 0);
        cur = 300;
        sum = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (timestamp > cur) {
            int count = 0;
            for (int i = cur + 1; i <= timestamp && count < 300; i++, count++) {
                sum -= ts[i % 300];
                ts[i % 300] = 0;
            }
            cur = timestamp;
        }
        ts[timestamp % 300]++;
        sum++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        if (timestamp > cur) {
            int count = 0;
            for (int i = cur + 1; i <= timestamp && count < 300; i++, count++) {
                sum -= ts[i % 300];
                ts[i % 300] = 0;
            }
            cur = timestamp;
        }
        return sum;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
