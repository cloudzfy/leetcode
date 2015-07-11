class Solution {
public:
    int reverse(int x) {
        bool minus = false;
        if (x < 0)
        {
            minus = true;
            x = -x;
            if (x == -2147483648)
            {
                return 0;
            }
        }
        int ans = 0;
        int max = 214748364;
        while (x != 0)
        {
            if (minus)
            {
                if (ans > max || (ans == max && x > 8))
                {
                    ans = 0;
                    break;
                }
                else if (ans == max && x == 8)
                {
                    ans = - ans - x;
                    minus = false;
                    break;
                }
            }
            else
            {
                if (ans > max || (ans == max && x > 7))
                {
                    ans = 0;
                    break;
                }
            }
            ans = ans * 10 + x % 10;
            x = x / 10;
        }
        if (minus)
        {
            ans = - ans;
        }
        return ans;
    }
};