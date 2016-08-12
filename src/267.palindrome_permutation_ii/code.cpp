class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<int> count(128, 0);
        vector<string> ans;
        for (int i = 0; i < s.length(); i++) {
            count[s[i]]++;
        }
        int odd = 0;
        string single;
        for (int i = 0; i < 128; i++) {
            if (count[i] % 2) {
                odd++;
                single = i;
            }
        }
        if ((odd == 1 && s.length() % 2 == 0) || (odd > 1)) return ans;
        string myans;
        for (int i = 0; i < 128; i++) {
            while (count[i] - 2 >= 0) {
                count[i] -= 2;
                myans += i;
            }
        }
        if (myans.length() > 0) {
            do {
                if (odd) ans.push_back(myans + single + reverse(myans));
                else ans.push_back(myans + reverse(myans));
            }while(nextPermutation(myans));
        } else ans.push_back(single);
        return ans;
    }
    bool nextPermutation(string& s) {
        int i = s.length() - 1;
        while (i > 0 && s[i - 1] >= s[i]) i--;
        if (i == 0) return false;
        int j = i;
        while (j + 1 < s.length() && s[i - 1] < s[j + 1]) j++;
        swap(s[i - 1], s[j]);
        j = s.length() - 1;
        while (i < j) swap(s[i++], s[j--]);
        return true;
    }
    string reverse(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            swap(s[left++], s[right--]);
        }
        return s;
    }
};
