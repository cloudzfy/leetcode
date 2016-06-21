class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int y = 0, tmpx = x;
        while (tmpx) {
            int tmp = tmpx % 10;
            tmpx /= 10;
            y *= 10;
            y += tmp;
        }
        return x == y;
    }
};
