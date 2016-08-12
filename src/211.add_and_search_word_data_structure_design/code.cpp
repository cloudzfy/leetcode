class TrieNode {
    public:
    TrieNode() {
        hasWord = false;
        memset(next, 0, sizeof(next));
    }
    bool hasWord;
    TrieNode* next[26];
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.length(); i++) {
            if (p->next[word[i] - 'a'] == NULL) {
                p->next[word[i] - 'a'] = new TrieNode();
            }
            p = p->next[word[i] - 'a'];
        }
        p->hasWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(word, 0, root);
    }
    
    bool search(string word, int index, TrieNode* node) {
        TrieNode *p = node;
        for (int i = index; i < word.length(); i++) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; j++) {
                    if (p->next[j] != NULL && search(word, i + 1, p->next[j])) return true;
                }
                return false;
            }
            if (p->next[word[i] - 'a'] == NULL) return false;
            p = p->next[word[i] - 'a'];
        }
        return p->hasWord;
    }
private:
    TrieNode *root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
