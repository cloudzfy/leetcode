class Solution {
public:
    bool isValid(string s) {
        stack<char> x;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{') x.push(ch);
            else if (x.empty()) return false;
            else if (s[i] == ')') {
                if (x.top() == '(') x.pop();
                else return false;
            }
            else if (s[i] == ']') {
                if (x.top() == '[') x.pop();
                else return false;
            }
            else if (s[i] == '}') {
                if (x.top() == '{') x.pop();
                else return false;
            }
        }
        if (x.empty()) return true;
        return false;
    }
};
