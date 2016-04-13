class Solution {
private:
    unordered_map<string, int> pathLevel;
    unordered_map<string, vector<string>> nextNode;
    vector<vector<string>> ans;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        bfs(wordList, beginWord, endWord);
        vector<string> myans;
        dfs(wordList, beginWord, endWord, myans);
        return ans;
    }
    
    void bfs(unordered_set<string>& wordList, string beginWord, string endWord) {
        queue<string> q;
        q.push(beginWord);
        pathLevel[beginWord] = 0;
        while (!q.empty()) {
            string curWord = q.front();
            q.pop();
            int level = pathLevel[curWord];
            if (curWord == endWord) continue;
            vector<string> myNextNode;
            for (int i = 0; i < curWord.length(); i++) {
                string nextWord = curWord;
                for (int j = 0; j < 26; j++) {
                    if (curWord[i] == 'a' + j) continue;
                    nextWord[i] = 'a' + j;
                    if (wordList.find(nextWord) == wordList.end()) continue;
                    if (pathLevel.find(nextWord) == pathLevel.end()) {
                        pathLevel[nextWord] = level + 1;
                        q.push(nextWord);
                    }
                    if (pathLevel[nextWord] == level + 1) myNextNode.push_back(nextWord);
                }
            }
            nextNode[curWord] = myNextNode;
        }
    }
    
    void dfs(unordered_set<string>& wordList, string curWord, string endWord, vector<string>& myans) {
        myans.push_back(curWord);
        if (curWord == endWord) {
            ans.push_back(myans);
            myans.pop_back();
            return;
        }
        int level = pathLevel[curWord];
        vector<string> myNextNode = nextNode[curWord];
        for (int i = 0; i < myNextNode.size(); i++) {
            dfs(wordList, myNextNode[i], endWord, myans);
        }
        myans.pop_back();
    }

};
