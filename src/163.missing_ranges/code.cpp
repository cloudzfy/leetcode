class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == lower) lower++;
            else if (nums[i] > lower) {
                addRange(ans, lower, min(upper, nums[i] - 1));
                lower = nums[i] + 1;
            }
        }
        if (lower <= upper) addRange(ans, lower, upper);
        return ans;
    }
    void addRange(vector<string>& ans, int begin, int end) {
        if (begin > end) return;
        char range[50];
        if (begin == end) sprintf(range, "%d", begin);
        else sprintf(range, "%d->%d", begin, end);
        ans.push_back(range);
    }
};
