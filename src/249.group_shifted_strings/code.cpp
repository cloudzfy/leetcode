class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strings.size(); i++) {
            m[getPattern(strings[i])].push_back(strings[i]);
        }
        vector<vector<string>> ans;
        for (auto it = m.begin(); it != m.end(); it++) {
            sort(it->second.begin(), it->second.end());
            ans.push_back(it->second);
        }
        return ans;
    }
    
    string getPattern(string str) {
        int diff = str[0] - 'a';
        for (int i = 0; i < str.length(); i++) {
            if (str[i] - diff < 'a') str[i] -= diff - 26;
            else str[i] -= diff;
        }
        return str;
    }
};
