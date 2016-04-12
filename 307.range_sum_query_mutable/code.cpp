class NumArray {
private:
    vector<int> origin;
    vector<int> segment;
public:
    NumArray(vector<int> &nums) {
        segment.resize(nums.size() + 1);
        origin = nums;
        for (int i = 0; i < nums.size(); i++) {
            add(i + 1, nums[i]);
        }
    }

    void update(int i, int val) {
        int num = val - origin[i];
        origin[i] = val;
        add(i + 1, num);
    }

    int sumRange(int i, int j) {
        return sum(j + 1) - sum(i);
    }
    
    int lowbit(int i) {
        return i & (-i);
    }
    
    void add(int i, int val) {
        while (i < segment.size()) {
            segment[i] += val;
            i += lowbit(i);
        }
    }
    
    int sum(int i) {
        int ans = 0;
        while (i > 0) {
            ans += segment[i];
            i -= lowbit(i);
        }
        return ans;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
