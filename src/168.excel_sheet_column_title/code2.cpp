class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while (n) {
            char ch;
            if (n % 26 == 0) {
                ch = 'Z';
                n -= 26;
            } else {
                ch = 'A' + n % 26 - 1;
                n -= n % 26;
            }
            ans = ch + ans;
            n /= 26;
        }
        return ans;
    }
};
