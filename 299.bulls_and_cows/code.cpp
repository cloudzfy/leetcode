class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> mS(10, 0);
        vector<int> mG(10, 0);
        int bulls = 0, cows = 0;
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                mS[secret[i] - '0']++;
                mG[guess[i] - '0']++;
            }
        }
        for (int i = 0; i < mS.size(); i++) {
            cows += min(mS[i], mG[i]);
        }
        char ans[50];
        sprintf(ans, "%dA%dB", bulls, cows);
        return ans;
        
    }
};
