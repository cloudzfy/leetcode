class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        string ans;
        int len = (numRows - 1) * 2;
        int left = 0, right = len;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < s.length(); j += len) {
                if (j + left < s.length()) ans += s[j + left];
                if (j + right < s.length() && right < len && left < right) ans += s[j + right];
            }
            left++;
            right--;
        }
        return ans;
    }
};
