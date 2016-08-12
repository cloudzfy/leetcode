class Solution {
public:
    string alienOrder(vector<string>& words) {
        string ans;
        vector<bool> isExist(26, false);
        vector<int> indegree(26, 0);
        vector<vector<bool>> graph(26, vector<bool>(26, false));
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].length(); j++) {
                isExist[words[i][j] - 'a'] = true;
            }
        }
        for (int i = 1; i < words.size(); i++) {
            for (int j = 0; j < words[i].length() && j < words[i - 1].length(); j++) {
                if (words[i][j] != words[i - 1][j]) {
                    if (!graph[words[i - 1][j] - 'a'][words[i][j] - 'a']) {
                        graph[words[i - 1][j] - 'a'][words[i][j] - 'a'] = true;
                        indegree[words[i][j] - 'a']++;
                    }
                    break;
                }
            }
        }
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (isExist[i] && indegree[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            ans += cur + 'a';
            for(int i = 0; i < 26; i++) {
                if (isExist[i] && graph[cur][i]) {
                    graph[cur][i] = false;
                    indegree[i]--;
                    if (indegree[i] == 0) q.push(i);
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            if (indegree[i] > 0) return "";
        }
        return ans;
    }
};
