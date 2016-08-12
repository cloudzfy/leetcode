class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;
        for (int i = 0; i < nums.size(); i++) {
            while (!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
            if (i >= k - 1) ans.push_back(nums[q.front()]);
            while (!q.empty() && q.front() <= i - k + 1) q.pop_front();
        }
        return ans;
    }
};
