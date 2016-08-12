class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> m(128, 0);
        int left = 0;
        int count = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            m[s[i]]++;
            if (m[s[i]] == 1) count++;
            if (count > 2) {
                m[s[left]]--;
                if (m[s[left]] == 0) count--;
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
