class Solution {
public:
    void reverseWords(string &s) {
        s = removeDuplicates(s);
        int len = s.length();
        reverse(s, 0, len - 1);
        int start = -1;
        for (int i = 0; s[i] != 0; i++) {
            if (s[i] != ' ' && start == -1) {
                start = i;
            }
            if (start != -1 && (s[i + 1] == ' ' || s[i + 1] == 0)) {
                reverse(s, start, i);
                start = -1;
            }
        }
    }
    void reverse(string &s, int left, int right) {
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
    string removeDuplicates(string s) {
        bool isBegin = true;
        string ans;
        int start = -1;
        for (int i = 0; s[i] != 0; i++) {
            if (s[i] != ' ' && start == -1) {
                start = i;
            }
            if (start != -1 && (s[i + 1] == ' ' || s[i + 1] == 0)) {
                if (!isBegin) ans.append(" ");
                isBegin = false;
                ans.append(s.substr(start, i - start + 1));
                start = -1;
            }
        }
        return ans;
    }
};
