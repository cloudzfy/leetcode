class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (int i = 0; i < nums.size(); i++) {
            strs.push_back(to_string(nums[i]));
        }
        sort(strs.begin(), strs.end(), cmp);
        string ans;
        bool leading = true;
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i] == "0" && leading) continue;
            ans += strs[i];
            leading = false;
        }
        if (ans == "") return "0";
        return ans;
    }
    
    static bool cmp(const string &a, const string &b) {
        return a + b > b + a;
    }
};
