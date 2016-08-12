class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        unordered_map<long long, int> m;
        string ans;
        char integer[20];
        long long numeratorLL = (long long)numerator;
        long long denominatorLL = (long long)denominator;
        long long sign = 1;
        if (numerator < 0) {
            sign *= -1;
            numeratorLL = -numeratorLL;
        }
        if (denominator < 0) {
            sign *= -1;
            denominatorLL = -denominatorLL;
        }
        sprintf(integer, "%lld", numeratorLL / denominatorLL);
        ans.append(integer);
        if (sign == -1 && numerator != 0) ans = "-" + ans;
        long long num = numeratorLL % denominatorLL;
        if (num == 0) return ans;
        ans.append(".");
        string decimal;
        do {
            m[num] = decimal.length();
            num *= 10;
            while (num < denominatorLL) {
                decimal.append("0");
                m[num] = decimal.length();
                num *= 10;
            }
            char mydecimal[5];
            sprintf(mydecimal, "%lld", num / denominatorLL);
            decimal.append(mydecimal);
            num %= denominatorLL;
            if (num == 0) return ans + decimal;
        }while(m.find(num) == m.end());
        ans.append(decimal.substr(0, m[num]));
        ans.append("(" + decimal.substr(m[num], decimal.length() - m[num]) + ")");
        return ans;
    }
};
