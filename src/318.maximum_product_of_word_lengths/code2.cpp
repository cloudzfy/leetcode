class Solution {
public:
    int maxProduct(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        int n = words.size();
        vector<int> bits(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].length(); j++) {
                bits[i] |= 1 << (words[i][j] - 'a');
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!(bits[i] & bits[j])) {
                    ans = max(ans, (int)words[i].length() * (int)words[j].length());
                    break;
                }
            }
        }
        return ans;
    }
    static bool cmp(string a, string b) {
        return a.length() > b.length();
    }
};
