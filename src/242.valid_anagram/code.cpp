class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        map<char, int> mS, mT;
        for (int i = 0; i < s.length(); i++) {
            mS[s[i]]++;
        }
        for (int i = 0; i < t.length(); i++) {
            if (mS.find(t[i]) != mS.end()) {
                mT[t[i]]++;
                if (mT[t[i]] > mS[t[i]]) return false;
            } else return false;
        }
        return true;
    }
};
