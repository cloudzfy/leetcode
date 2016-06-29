class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        queue<pair<string, int> > q;
        q.push(make_pair(beginWord, 1));
        wordList.erase(beginWord);
        while (!q.empty()) {
            string u = q.front().first;
            int len = q.front().second;
            q.pop();
            for (int i = 0; i < u.length(); i++) {
                for (int j = 0; j < 26; j++) {
                    if (u[i] == 'a' + j) continue;
                    string tmp = u;
                    tmp[i] = 'a' + j;
                    if (wordList.find(tmp) != wordList.end()) {
                        if (tmp == endWord) return len + 1;
                        q.push(make_pair(tmp, len + 1));
                        wordList.erase(tmp);
                    }
                }
            }
        }
        return 0;
    }
};
