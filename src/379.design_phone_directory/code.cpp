class PhoneDirectory {
private:
    vector<bool> used;
    vector<int> nums;
    int head, maxNumbers;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) : maxNumbers(maxNumbers) {
        for (int i = 0; i < maxNumbers; i++) {
            used.push_back(false);
            nums.push_back(i);
        }
        head = 0;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (head >= maxNumbers) return -1;
        int val = nums[head++];
        used[val] = true;
        return val;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if (number >= maxNumbers) return false;
        return !used[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (number < maxNumbers && used[number]) {
            used[number] = false;
            nums[--head] = number;
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
