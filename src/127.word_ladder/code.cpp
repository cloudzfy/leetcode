class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (wordList.size() == 0) return 0;
        map<string, int> step;
        queue<string> q;
        q.push(beginWord);
        step[beginWord] = 1;
        while (!q.empty()) {
            string curWord = q.front();
            q.pop();
            if (curWord == endWord) continue;
            for (int i = 0; i < curWord.length(); i++) {
                string myWord = curWord;
                for (int j = 0; j < 26; j++) {
                    if (curWord[i] == 'a' + j) continue;
                    myWord[i] = 'a' + j;
                    if (wordList.find(myWord) == wordList.end()) continue;
                    if (step.find(myWord) != step.end() && step[myWord] <= step[curWord] + 1) continue;
                    q.push(myWord);
                    step[myWord] = step[curWord] + 1;
                }
            }
        }
        return step[endWord];
    }
};
