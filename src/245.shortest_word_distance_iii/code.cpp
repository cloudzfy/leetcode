class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        if (word1 == word2) return shortestWordDistance2(words, word1);
        int ans = INT_MAX;
        int idx1 = -1, idx2 = -1;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                idx1 = i;
                if (idx2 != -1) ans = min(ans, i - idx2);
            }
            if (words[i] == word2) {
                idx2 = i;
                if (idx1 != -1) ans = min(ans, i - idx1);
            }
        }
        return ans;
    }
    int shortestWordDistance2(vector<string>& words, string word) {
        int ans = INT_MAX;
        int idx = -1;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word) {
                if (idx != -1) ans = min(ans, i - idx);
                idx = i;
            }
        }
        return ans;
    }
};
