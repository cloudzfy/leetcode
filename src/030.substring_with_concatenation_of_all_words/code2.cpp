class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int nWords = words.size();
        if (nWords == 0) return ans;
        int lenWord = words[0].length();
        if (s.length() < lenWord) return ans;
        unordered_map<string, int> originalWords;
        for (int i = 0; i < nWords; i++) {
            originalWords[words[i]]++;
        }
        for (int i = 0; i < lenWord; i++) {
            unordered_map<string, int> myWords;
            int count = 0;
            int left = i;
            for (int j = i; j <= s.length() - lenWord; j += lenWord) {
                string word = s.substr(j, lenWord);
                if (originalWords.find(word) != originalWords.end()) {
                    myWords[word]++;
                    count++;
                    while (myWords[word] > originalWords[word]) {
                        myWords[s.substr(left, lenWord)]--;
                        count--;
                        left += lenWord;
                    }
                    if (count == nWords) ans.push_back(left);
                } else {
                    myWords.clear();
                    count = 0;
                    left = j + lenWord;
                }
            }
        }
        return ans;
    }
};
