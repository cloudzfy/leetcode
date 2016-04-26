class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        int n = word.length();
        for (int i = 0; i < (1 << n); i++) {
            string myans;
            int start = -1;
            for (int j = 0; j < n; j++) {
                if ((1 << j) & i) {
                    if (start == -1) start = j;
                } else {
                    if (start != -1) {
                        myans += to_string(j - start);
                        start = -1;
                    }
                    myans += word[j];
                }
            }
            if (start != -1) myans += to_string(n - start);
            ans.push_back(myans);
        }
        return ans;
    }
};
