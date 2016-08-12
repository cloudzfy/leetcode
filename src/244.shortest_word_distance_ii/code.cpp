class WordDistance {
private:
    unordered_map<string, vector<int>> m;
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            m[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int ans = INT_MAX;
        vector<int> a = m[word1];
        vector<int> b = m[word2];
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                ans = min(ans, abs(a[i] - b[j]));
            }
        }
        return ans;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
