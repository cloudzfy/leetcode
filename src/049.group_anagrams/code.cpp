class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mstrs;
        for (int i = 0; i < strs.size(); i++) {
            string s(strs[i]);
            sort(s.begin(), s.end());
            mstrs[s].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (map<string, vector<string>>::iterator it = mstrs.begin(); it != mstrs.end(); it++) {
            vector<string> tmp = it->second;
            sort(tmp.begin(), tmp.end());
            ans.push_back(tmp);
        }
        return ans;
    }
};
