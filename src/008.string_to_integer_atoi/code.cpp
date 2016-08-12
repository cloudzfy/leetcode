class Solution {
public:
    int myAtoi(string str) {
        if (str.length() == 0) return 0;
        int sign = 1;
        int i = 0;
        long long num = 0;
        while (str[i] == ' ') i++;
        if (str[i] == '-') {
            sign *= -1;
            i++;
        } else if (str[i] == '+') i++;
        bool checkSign = false;
        for (;i < str.length(); i++) {
            if (str[i] <= '9' && str[i] >= '0') {
                if (sign == 1) num = num * 10 + (str[i] - '0');
                else num = num * 10 - (str[i] - '0');
            } else break;
            if (sign == 1 && (num < 0 || num > INT_MAX)) return INT_MAX;
            if (sign == -1 && (num > 0 || num < INT_MIN)) return INT_MIN;
        }
        return num;
    }
};
