class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        int maxNum = *max_element(nums.begin(), nums.end());
        int minNum = *min_element(nums.begin(), nums.end());
        if (maxNum == minNum) return 0;
        double bucketSize = (double)(maxNum - minNum) / (n - 1);
        vector<pair<int, int> > buckets(n, make_pair(INT_MAX, INT_MIN));
        for (int i = 0; i < n; i++) {
            int idx = (nums[i] - minNum) / bucketSize;
            buckets[idx].first = min(buckets[idx].first, nums[i]);
            buckets[idx].second = max(buckets[idx].second, nums[i]);
        }
        int ans = buckets[0].second - buckets[0].first;
        int pre = buckets[0].second;
        for (int i = 1; i < n; i++) {
            if (buckets[i].first == INT_MAX) continue;
            ans = max(ans, max(buckets[i].first - pre, buckets[i].second - buckets[i].first));
            pre = buckets[i].second;
        }
        return ans;
    }
};
