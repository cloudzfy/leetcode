class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<int, int> m;
        int count = 0;
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            num <<= 2;
            num += convert(s[i]);
            count++;
            if (count >= 10) {
                num &= (1 << 20) - 1;
                m[num]++;
                if (m[num] == 2) {
                    ans.push_back(s.substr(i - 9, 10));
                }
            }
        }
        return ans;
    }
    int convert(char ch) {
        if (ch == 'A') return 0;
        if (ch == 'T') return 1;
        if (ch == 'C') return 2;
        if (ch == 'G') return 3;
    }
};
