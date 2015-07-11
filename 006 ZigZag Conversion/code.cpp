class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        for (int r = 0; r < numRows; r++)
        {
            int i = 0;
            while(i < s.length())
            {
                if (i + r == i + max(1, 2 * (numRows - 1)) - r)
                {
                    if (i + r < s.length())
                    {
                        ans.push_back(s[i + r]);
                    }
                }
                else
                {
                    if (i + r < s.length())
                    {
                        ans.push_back(s[i + r]);
                    }
                    if (i + max(1, 2 * (numRows - 1)) - r < s.length() && r != 0)
                    {
                        ans.push_back(s[i + max(1, 2 * (numRows - 1)) - r]);
                    }
                }
                i += max (1, 2 * (numRows - 1));
            }
        }
        return ans;
    }
};