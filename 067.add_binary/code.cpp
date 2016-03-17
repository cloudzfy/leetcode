class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0) {
            if (i >= 0) {
                carry += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                carry += b[j] - '0';
                j--;
            }
            char ch = carry % 2 + '0';
            ans = ch + ans;
            carry /= 2;
        }
        while (carry != 0) {
            char ch = carry % 2 + '0';
            ans = ch + ans;
            carry /= 2;
        }
        return ans;
    }
};
