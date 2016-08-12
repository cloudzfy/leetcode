class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        if (n < 2) return s;
        vector<int> next(n, 0);
        getNext(s, next);
        int len = kmp(s, next);
        string tmp = s.substr(len, n - len);
        reverse(tmp, 0, tmp.length() - 1);
        return tmp + s;
    }
    void reverse(string& s, int left, int right) {
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
    void getNext(string& s, vector<int>& next) {
        next[0] = -1;
        int i = 0, j = -1;
        while (i < s.length() - 1) {
            if (j == -1 || s[i] == s[j]) {
                next[++i] = ++j;
            } else {
                j = next[j];
            }
        }
    }
    int kmp(string& s, vector<int>& next) {
        int i = s.length() - 1, j = 0;
        while (j < i) {
            if (j == -1 || s[i] == s[j]) {
                i--;
                j++;
            } else {
                j = next[j];
            }
        }
        return i + j + 1;
    }
};
