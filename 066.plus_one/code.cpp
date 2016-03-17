class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int carry = 1;
        for (int i = len - 1; i >= 0; i--) {
            digits[i] += carry;
            if (digits[i] >= 10) {
                digits[i] %= 10;
                carry = 1;
            }
            else carry = 0;
        }
        if (carry != 0) {
            digits.push_back(digits[len-1]);
            for (int i = len - 1; i >= 1; i--) {
                digits[i] = digits[i-1];
            }
            digits[0] = 1;
        }
        return digits;
    }
};
