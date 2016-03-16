class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x < 10)
            return true;
        int a = 1, b = 1;
        int tmp = x;
        while (tmp >= 10) {
            tmp = tmp / 10;
            a = a * 10;
        }
        while (a >= b) {
            if (x / a % 10 != x / b % 10)
                return false;
            a = a / 10;
            b = b * 10;
        }
        return true;
    }
};
