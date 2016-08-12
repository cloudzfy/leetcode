class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> m(26, 0);
        for (int i = 0; i < magazine.length(); i++) {
            m[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.length(); i++) {
            m[ransomNote[i] - 'a']--;
            if (m[ransomNote[i] - 'a'] < 0) return false;
        }
        return true;
    }
};
