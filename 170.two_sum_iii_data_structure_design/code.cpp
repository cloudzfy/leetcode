class TwoSum {
private:
    unordered_map<int, int> m;
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    m[number]++;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
	        int num = value - it->first;
	        if (it->first < num && m.find(num) != m.end()) return true;
	        if (it->second > 1 && it->first == num) return true;
	    }
	    return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
