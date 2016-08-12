class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int prod = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                prod = 1;
                maxProd = max(maxProd, 0);
            }
            else {
                prod *= nums[i];
                maxProd = max(maxProd, prod);
            }
        }
        prod = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == 0) {
                prod = 1;
                maxProd = max(maxProd, 0);
            }
            else {
                prod *= nums[i];
                maxProd = max(maxProd, prod);
            }
        }
        return maxProd;
    }
};
