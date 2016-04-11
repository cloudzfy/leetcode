class Solution {
public:
    int calculate(string s) {
        stack<char> symbols;
        stack<int> values;
        int num = 0;
        bool wasDigit = false;
        for (int i = 0; i <= s.length(); i++) {
            if (s[i] == ' ') continue;
            if (isDigit(s[i])) {
                num *= 10;
                num += s[i] - '0';
                wasDigit = true;
                continue;
            }
            if (wasDigit) {
                wasDigit = false;
                values.push(num);
                num = 0;
                if (!symbols.empty()) {
                   char op = symbols.top();
                    if (op == '+' || op == '-') {
                        symbols.pop();
                        int num1 = values.top();
                        values.pop();
                        int num2 = values.top();
                        values.pop();
                        if (op == '+') num2 += num1;
                        if (op == '-') num2 -= num1;
                        values.push(num2);
                    }
                }
            }
            if (s[i] == '+' || s[i] == '-' || s[i] == '(') {
                symbols.push(s[i]);
                continue;
            }
            if (s[i] == ')') {
                while(!symbols.empty()) {
                    char op = symbols.top();
                    symbols.pop();
                    if (op == '+' || op == '-') {
                        int num1 = values.top();
                        values.pop();
                        int num2 = values.top();
                        values.pop();
                        if (op == '+') num2 += num1;
                        if (op == '-') num2 -= num1;
                        values.push(num2);
                    } else if (op == '(') break;
                }
                if (!symbols.empty()) {
                   char op = symbols.top();
                    if (op == '+' || op == '-') {
                        symbols.pop();
                        int num1 = values.top();
                        values.pop();
                        int num2 = values.top();
                        values.pop();
                        if (op == '+') num2 += num1;
                        if (op == '-') num2 -= num1;
                        values.push(num2);
                    }
                }
            }
        }
        return values.top();
    }
    bool isDigit(char c) {
        if (c <= '9' && c >= '0') return true;
        return false;
    }
};
