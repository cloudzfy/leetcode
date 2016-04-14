class TrieNode {
public:
    TrieNode() {
        hasWord = false;
        wordCount = 0;
        memset(next, 0, sizeof(next));
    }
    bool hasWord;
    int wordCount;
    TrieNode* next[26];
};

class Solution {
private:
    vector<string> ans;
    int n, m;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        if (n == 0) return ans;
        m = board[0].size();
        if (m == 0) return ans;
        TrieNode *root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            TrieNode *p = root;
            for (int j = 0; j < words[i].length(); j++) {
                if (p->next[words[i][j] - 'a'] == NULL) {
                    p->next[words[i][j] - 'a'] = new TrieNode();
                }
                p = p->next[words[i][j] - 'a'];
                p->wordCount++;
            }
            p->hasWord = true;
        }
        string myans;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                search(board, visited, i, j, root, myans);
            }
        }
        return ans;
    }
    int search(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, TrieNode *node, string myans) {
        TrieNode *p = node->next[board[i][j] - 'a'];
        if (p) {
            visited[i][j] = true;
            myans.append(1, board[i][j]);
            int sum = 0;
            if (p->hasWord) {
                p->hasWord = false;
                ans.push_back(myans);
                sum++;
            }
            if (i - 1 >= 0 && !visited[i - 1][j]) sum += search(board, visited, i - 1, j, p, myans);
            if (i + 1 < n && !visited[i + 1][j]) sum += search(board, visited, i + 1, j, p, myans);
            if (j - 1 >= 0 && !visited[i][j - 1]) sum += search(board, visited, i, j - 1, p, myans);
            if (j + 1 < m && !visited[i][j + 1]) sum += search(board, visited, i, j + 1, p, myans);
            p->wordCount -= sum;
            if (p->wordCount == 0) node->next[board[i][j] - 'a'] = NULL;
            visited[i][j] = false;
            return sum;
        }
        return 0;
    }
};
