class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int> > minHeap;
    priority_queue<int, vector<int>, less<int> > maxHeap;
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if (minHeap.size() > 0 && minHeap.top() < num) minHeap.push(num);
        else maxHeap.push(num);
    }

    // Returns the median of current data stream
    double findMedian() {
        while (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        while (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        else return ((double)minHeap.top() + (double)maxHeap.top()) / 2;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
