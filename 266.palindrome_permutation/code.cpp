class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> m(128, 0);
        for (int i = 0; i < s.length(); i++) {
            m[s[i]]++;
        }
        int count = 0;
        for (int i = 0; i < 128; i++) {
            if (m[i] % 2 == 1) count++;
        }
        return count == s.length() % 2;
    }
};
