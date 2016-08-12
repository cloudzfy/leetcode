class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        vector<int> bucketMin(n, INT_MAX);
        vector<int> bucketMax(n, INT_MIN);
        vector<int> isEmpty(n, true);
        int numMin = INT_MAX, numMax = INT_MIN;
        for (int i = 0; i < n; i++) {
            numMin = min(numMin, nums[i]);
            numMax = max(numMax, nums[i]);
        }
        if (numMax == numMin) return 0;
        double step = (double)(numMax - numMin) / (double)(n - 1);
        for (int i = 0; i < n; i++) {
            int index = min((int)((nums[i] - numMin) / step), n - 1);
            bucketMin[index] = min(bucketMin[index], nums[i]);
            bucketMax[index] = max(bucketMax[index], nums[i]);
            isEmpty[index] = false;
        }
        int ans = 0, tmpMax, tmpMin;
        bool hasMax = false;
        for (int i = 0; i < n; i++) {
            if (isEmpty[i]) continue;
            tmpMin = bucketMin[i];
            if (hasMax) ans = max(ans, tmpMin - tmpMax);
            tmpMax = bucketMax[i];
            hasMax = true;
        }
        return ans;
    }
};
