class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, three = 0;
        for (int i = 0; i < nums.size(); i++) {
            int tmp1 = three & nums[i];
            three -= tmp1;
            nums[i] -= tmp1;
            int tmp2 = two & nums[i];
            three |= tmp2;
            two -= tmp2;
            nums[i] -= tmp2;
            tmp2 = one & nums[i];
            two |= tmp2;
            one -= tmp2;
            nums[i] -= tmp2;
            one |= tmp1 | nums[i];
        }
        return one;
    }
};
