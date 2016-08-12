class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int> > m;
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(0));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        m[val].insert(nums.size());
        nums.push_back(val);
        return m[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (m[val].size() == 0) return false;
        if (val == nums.back()) {
            nums.pop_back();
            m[val].erase(nums.size());
            return true;
        }
        int idx = *(m[val].begin());
        nums[idx] = nums.back();
        m[nums.back()].erase(nums.size() - 1);
        m[val].erase(idx);
        m[nums.back()].insert(idx);
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int idx = (double) rand() / RAND_MAX * nums.size();
        return nums[idx];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
