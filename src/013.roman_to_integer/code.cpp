class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        if (len < 1) return 0;
        int num = charToInt(s[len - 1]);
        int left, right = num;
        for (int i = len - 2; i >= 0; i--) {
            left = charToInt(s[i]);
            if (left >= right) num += left;
            else num -= left;
            right = left;
        }
        return num;
    }
    int charToInt(char x) {
        if (x == 'I') return 1;
        else if (x == 'V') return 5;
        else if (x == 'X') return 10;
        else if (x == 'L') return 50;
        else if (x == 'C') return 100;
        else if (x == 'D') return 500;
        else if (x == 'M') return 1000;
        else return 0;
    }
};
