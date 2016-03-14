class Solution {
public:
    string longestPalindrome(string s) {
        bool f[1010][1010];
        int idx = 0, idy = 1, len = 1;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 0; j < s.length(); j++)
            {
                f[i][j] = false;
            }
        }
        f[0][0] = true;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i-1] == s[i])
            {
                f[i-1][i] = true;
                f[i][i-1] = true;
                len = 2;
                idx = i - 1;
                idy = i;
            }
            f[i][i] = true;
        }
        for (int j = 1; j < s.length(); j++)
        {
            for(int i = 0; i < j; i++)
            {
                if(s[i] == s[j])
                {
                    f[i][j] = f[i + 1][j - 1];
                }
                else
                {
                    f[i][j] = false;
                }
                if(f[i][j] && j - i + 1 > len)
                {
                    len = j - i + 1;
                    idx = i;
                    idy = j;
                }
            }
        }
        return s.substr(idx, idy - idx + 1);
    }
};