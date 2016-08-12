class TwoSum {
private:
    unordered_multiset<int> m;
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    m.insert(number);
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for (int num : m) {
	        if (num > value - num) continue;
	        int count = num == value - num ? 1 : 0;
	        if (m.count(value - num) > count) return true;
	    }
	    return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
