class Solution {
public:
    int myAtoi(string str) {
        int num = 0, sign = 1;
        int idx = 0;
        while (str[idx] == ' ') idx++;
        if (str[idx] == '-') {
            sign = -1;
            idx++;
        } else if (str[idx] == '+') idx++;
        for (int i = idx; i < str.length(); i++) {
            if (str[i] <= '9' && str[i] >= '0') {
                if (num > INT_MAX / 10) return sign == 1 ? INT_MAX : INT_MIN;
                if (num == INT_MAX / 10) {
                    if (sign == 1 && str[i] >= '7') return INT_MAX;
                    if (sign == -1 && str[i] >= '8') return INT_MIN;
                } 
                num *= 10;
                num += str[i] - '0';
            } else break;
        }
        return num * sign;
    }
};
