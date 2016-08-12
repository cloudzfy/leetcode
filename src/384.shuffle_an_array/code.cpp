class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int> nums) : nums(nums) {
        srand(time(0));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffledNums(nums);
        for (int i = 0; i < shuffledNums.size(); i++) {
            int idx = (double) rand() / RAND_MAX * (i + 1);
            swap(shuffledNums[idx], shuffledNums[i]);
        }
        return shuffledNums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
