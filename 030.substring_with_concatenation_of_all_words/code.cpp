class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int nWords = words.size();
        if (nWords == 0) return ans;
        int lenWord = words[0].length();
        map<string, int> originalWords;
        for (int i = 0; i < words.size(); i++) {
            originalWords[words[i]]++;
        }
        for (int i = 0; i + nWords * lenWord <= s.length(); i++) {
            map<string, int> myWords;
            bool isSub = true;
            for (int j = 0; j < nWords && isSub; j++) {
                string word = s.substr(i + j * lenWord, lenWord);
                if (originalWords.find(word) != originalWords.end()) {
                    myWords[word]++;
                    if (myWords[word] > originalWords[word]) isSub = false;
                } else isSub = false;
            }
            if (isSub) ans.push_back(i);
        }
        return ans;
    }
};
