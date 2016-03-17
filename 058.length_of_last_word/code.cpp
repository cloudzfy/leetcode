class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int end = -1;
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                end = i;
                break;
            }
        }
        if (end == -1) return 0;
        int begin = 0;
        for (int i = end; i >= 0; i--) {
            if (s[i] == ' ') {
                begin = i + 1;
                break;
            }
        }
        return end - begin + 1;
    }
};
