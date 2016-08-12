class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, 0);
        int start = 0, ans = 0, local = 0;
        for (int i = 0; i < s.length(); i++) {
            m[s[i]]++;
            local++;
            while (m[s[i]] > 1) {
                m[s[start]]--;
                start++;
                local--;
            }
            ans = max(ans, local);
        }
        return ans;
    }
};
