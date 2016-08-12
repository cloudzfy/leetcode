class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); i++) {
            if (isOperator(tokens[i])) {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                if (tokens[i] == "+") num2 += num1;
                else if (tokens[i] == "-") num2 -= num1;
                else if (tokens[i] == "*") num2 *= num1;
                else num2 /= num1;
                s.push(num2);
            }
            else s.push(strToNum(tokens[i]));
        }
        return s.top();
    }
    int strToNum(string str) {
        int num;
        sscanf(&str[0], "%d", &num);
        return num;
    }
    bool isOperator(string str) {
        return str == "+" || str == "-" || str == "*" || str == "/";
    }
};
