class Solution {
public:
    bool isAdditiveNumber(string num) {
        long long a, b, c;
        for (int i = 0; i < num.length(); i++) {
            for (int j = i + 1; j + 1 < num.length(); j++) {
                a = strToNum(num.substr(0, i + 1));
                b = strToNum(num.substr(i + 1, j - i));
                int k = j + 1;
                while (k < num.length()) {
                    c = a + b;
                    string tmp = numToStr(c);
                    if (!startWith(num.substr(k), tmp)) break;
                    a = b;
                    b = c;
                    k += tmp.length();
                }
                if (k == num.length()) return true;
                if (num[i + 1] == '0') break;
            }
            if (num[0] == '0') break;
        }
        return false;
    }
    long long strToNum(string str) {
        long long ans;
        sscanf(&str[0], "%lld", &ans);
        return ans;
    }
    string numToStr(long long num) {
        char ans[40];
        sprintf(ans, "%lld", num);
        return ans;
    }
    bool startWith(string str, string sub) {
        for (int i = 0; i < sub.length(); i++) {
            if (i == str.length()) return false;
            if (str[i] != sub[i]) return false;
        }
        return true;
    }
};
