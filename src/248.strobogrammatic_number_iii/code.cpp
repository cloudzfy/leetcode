class Solution {
private:
    string l = "01689";
    string r = "01986";
    string c = "018";
public:
    int strobogrammaticInRange(string low, string high) {
        int ans = 0;
        
        if (low.length() < high.length()) {
            countStrobogrammatic(low.length(), "", true, low, false, high, ans);
            countStrobogrammatic(high.length(), "", false, low, true, high, ans);
        } else if (low.length() == high.length()) {
            countStrobogrammatic(low.length(), "", true, low, true, high, ans);
        }
        for (int i = low.length() + 1; i < high.length(); i++) {
            int tmp = i % 2 ? 3 : 1;
            for (int j = 1; j < i / 2; j++) {
                tmp *= 5;
            }
            tmp *= 4;
            ans += tmp;
        }
        return ans;
    }
    
    void countStrobogrammatic(int length, string str, bool islbound, string low, bool isubound, string high, int &count) {
        if (length == 0) {
            if (islbound && !compare(low, str)) return;
            if (isubound && !compare(str, high)) return;
            count++;
            return;
        }
        if (length % 2) {
            for (int i = 0; i < 3; i++) {
                countStrobogrammatic(length - 1, str + c[i], islbound, low, isubound, high, count);
            }
        } else {
            for (int i = 0; i < 5; i++) {
                if (length == 2 && i == 0) continue;
                countStrobogrammatic(length - 2, l[i] + str + r[i], islbound, low, isubound, high, count);
            }
        }
    }
    
    bool compare(string x, string y) {
        for (int i = 0; i < x.length(); i++) {
            if (x[i] > y[i]) return false;
            if (x[i] < y[i]) return true;
        }
        return true;
    }
};
