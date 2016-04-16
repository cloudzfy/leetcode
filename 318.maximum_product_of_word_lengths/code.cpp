class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> bits(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].length(); j++) {
                bits[i] |= 1 << (words[i][j] - 'a');
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!(bits[i] & bits[j])) {
                    ans = max(ans, (int)words[i].length() * (int)words[j].length());
                }
            }
        }
        return ans;
    }
};
