class ValidWordAbbr {
private:
    unordered_map<string, unordered_set<string>> m;
    
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (int i = 0; i < dictionary.size(); i++) {
            int len = dictionary[i].length();
            string str = dictionary[i][0] + to_string(len - 2) + dictionary[i][len - 1];
            m[str].insert(dictionary[i]);
        }
    }

    bool isUnique(string word) {
        int len = word.length();
        string str = word[0] + to_string(len - 2) + word[len - 1];
        return m.find(str) == m.end() || (m[str].find(word) != m[str].end() && m[str].size() == 1);
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
