class Solution {
public:
    int myAtoi(string str) {
        int ans = 0;
        int max = 2147483647, min = -2147483648;
        bool sym = false, start = false, illegal = false, pos = true;
        for(int i = 0; i < str.length(); i++)
        {
            if (str[i] == ' ')
            {
                if (!start) continue;
                else break;
            }
            else start = true;
            if (str[i] == '+')
            {
                if (!sym)
                {
                    sym = true;
                    pos = true;
                    continue;
                }
                else
                {
                    illegal = true;
                    break;
                }
            }
            if (str[i] == '-')
            {
                if (!sym)
                {
                    sym = true;
                    pos = false;
                    continue;
                }
                else
                {
                    illegal = true;
                    break;
                }
            }
            if (str[i] > '9' || str[i] < '0') break;
            if (ans == min / 10)
            {
                if (pos && str[i] - '0' > 7)
                {
                    ans = -max;
                    continue;
                }
                else if (!pos && str[i] - '0' > 8)
                {
                    ans = min;
                    continue;
                }
            }
            if (ans < min / 10)
            {
                if (pos) ans = -max;
                if (!pos) ans = min;
                continue;
            }
            ans *= 10;
            ans -= str[i] - '0';
        }
        if (pos)
        {
            if (ans < -max)
            {
                ans = max;
            }
            else ans = -ans;
        }
        if (illegal) ans = 0;
        return ans;
    }
};