class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        int len3 = len1 + len2;
        string num3(len3, 0);
        for (int i = 0; i <= len1; i++) {
            num1[i] -= '0';
        }
        for (int i = 0; i <= len2; i++) {
            num2[i] -= '0';
        }
        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                int tmp = num3[i + j + 1] + num1[i] * num2[j];
                num3[i + j + 1] = tmp % 10;
                num3[i + j] += tmp / 10;
            }
        }
        for (int i = len3 - 1; i > 0; i--) {
            num3[i - 1] += num3[i] / 10;
            num3[i] = num3[i] % 10 + '0';
        }
        num3[0] += '0';
        for (int i = 0; i < len3; i++) {
            if (num3[i] != '0' || i == len3 - 1) {
                return num3.substr(i, len3 - i);
            }
        }
        return num3;
    }
};
