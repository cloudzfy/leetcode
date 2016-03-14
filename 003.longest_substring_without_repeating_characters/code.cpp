class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int ans = 0, j = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (m.find(s[i]) == m.end())
            {
                ans = max(ans, i - j + 1);
            }
            else
            {
                while(m.find(s[i]) != m.end())
                {
                    m.erase(m.find(s[j]));
                    j++;
                }
            }
            m[s[i]] = 1;
        }
        return ans;
    }
};