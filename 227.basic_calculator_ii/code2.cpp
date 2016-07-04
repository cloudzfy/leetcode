class Solution {
public:
    int calculate(string s) {
        int num = 0, term = 1, expr = 0;
        bool divided = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] <= '9' && s[i] >= '0') {
                num *= 10;
                num += s[i] - '0';
            } else if (s[i] == '*') {
                if (!divided) term *= num;
                else {
                    term /= num;
                    divided = false;
                }
                num = 0;
            } else if (s[i] == '/') {
                if (!divided) term *= num;
                else {
                    term /= num;
                    divided = false;
                }
                num = 0;
                divided = true;
            } else if (s[i] == '+') {
                if (!divided) expr += term * num;
                else {
                    expr += term / num;
                    divided = false;
                }
                term = 1;
                num = 0;
            } else if (s[i] == '-') {
                if (!divided) expr += term * num;
                else {
                    expr += term / num;
                    divided = false;
                }
                term = -1;
                num = 0;
            }
        }
        if (!divided) expr += term * num;
        else expr += term / num;
        return expr;
    }
};
