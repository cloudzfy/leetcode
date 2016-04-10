class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if (n == 0) return ans;
        int begin = 0;
        int cur = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == cur + 1) {
                cur = nums[i];
            } else {
                char range[30];
                if (begin < i - 1) sprintf(range, "%d->%d",nums[begin], nums[i - 1]);
                else sprintf(range, "%d", nums[begin]);
                string myans(range);
                ans.push_back(myans);
                begin = i;
                cur = nums[i];
            }
        }
        char range[30];
        if (begin < n - 1) sprintf(range, "%d->%d",nums[begin], nums[n - 1]);
        else sprintf(range, "%d", nums[begin]);
        string myans(range);
        ans.push_back(myans);
        return ans;
    }
};
