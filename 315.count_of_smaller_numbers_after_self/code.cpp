class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        vector<int> tree(n + 1, 0);
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            int tmp = search(sortedNums, nums[i]) + 1;
            add(tree, tmp);
            ans[i] = get(tree, tmp - 1);
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
    }
    int lowbit(int i) {
        return i & (-i);
    }
    void add(vector<int>& nums, int i) {
        while (i < nums.size()) {
            nums[i] += 1;
            i += lowbit(i);
        }
    }
    int get(vector<int>& nums, int i) {
        int ans = 0;
        while (i > 0) {
            ans += nums[i];
            i -= lowbit(i);
        }
        return ans;
    }
};
