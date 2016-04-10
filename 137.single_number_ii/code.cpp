class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int nBits = 32;
        vector<int> bits(nBits, 0);
        for (int i = 0; i < n; i++) {
            int tmp = nums[i];
            for (int j = 0; j < nBits; j++) {
                bits[j] += tmp & 1;
                tmp >>= 1;
                if (tmp == 0) break;
            }
        }
        int ans = 0;
        for (int i = nBits - 1; i >= 0; i--) {
            ans = ans << 1;
            ans += bits[i] % 3;
        }
        return ans;
    }
};
