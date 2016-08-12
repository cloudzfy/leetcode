class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (int i = 0; i < nums.size(); i++) {
            char str[12];
            sprintf(str, "%d", nums[i]);
            strs.push_back(str);
        }
        sort(strs.begin(), strs.end(), cmp);
        string ans;
        for (int i = strs.size() - 1; i >= 0; i--) {
            ans = ans + strs[i];
        }
        if (ans[0] == '0') {
            for (int i = 1; i < ans.length(); i++) {
                if (ans[i] != '0' || i == ans.length() - 1) {
                    return ans.substr(i, ans.length() - i);
                }
            }
        }
        return ans;
    }
    static bool cmp(string a, string b) {
        return a + b < b + a;
    }
};
