class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> wordList;
        vector<vector<int>> ans;
        set<int> s;
        for (int i = 0; i < words.size(); i++) {
            wordList[words[i]] = i;
            s.insert(words[i].length());
        }
        for (int i = 0; i < words.size(); i++) {
            string tmp = words[i];
            reverse(tmp.begin(), tmp.end());
            if (wordList.find(tmp) != wordList.end() && wordList[tmp] != i) {
                ans.push_back({i, wordList[tmp]});
            }
            int len = tmp.length();
            for (auto it = s.begin(); it != s.end(); it++) {
                int m = *it;
                if (m >= len) break;
                if (isPalin(tmp, 0, len - m - 1) && wordList.find(tmp.substr(len - m)) != wordList.end()) {
                    ans.push_back({i, wordList[tmp.substr(len - m)]});
                }
                if (isPalin(tmp, m, len - 1) && wordList.find(tmp.substr(0, m)) != wordList.end()) {
                    ans.push_back({wordList[tmp.substr(0, m)], i});
                }
            }
        }
        return ans;
    }
    bool isPalin(string str, int i, int j) {
        while (i < j) {
            if (str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
