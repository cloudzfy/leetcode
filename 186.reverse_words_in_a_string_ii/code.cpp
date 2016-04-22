class Solution {
public:
    void reverseWords(string &s) {
        int left = 0;
        for (int i = 0; i <= s.length(); i++) {
            if (s[i] == ' ' || s[i] == 0) {
                reverse(s, left, i - 1);
                left = i + 1;
            }
        }
        reverse(s, 0, s.length() - 1);
    }
    void reverse(string &s, int left, int right) {
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
};
