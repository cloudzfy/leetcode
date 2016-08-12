class Solution {
private:
    vector<string> ans;
    string l = "01869";
    string r = "01896";
public:
    vector<string> findStrobogrammatic(int n) {
        if (n % 2 == 1) {
            for (int i = 0; i < 3; i++) {
                generateStrobogrammatic((n - 1) / 2, l.substr(i, 1));
            }
        } else {
            generateStrobogrammatic(n / 2, "");
        }
        return ans;
    }
    void generateStrobogrammatic(int n, string myans) {
        if (n == 0) {
            ans.push_back(myans);
            return;
        }
        for (int i = 0; i < 5; i++) {
            if (n == 1 && i == 0) continue;
            generateStrobogrammatic(n - 1, l[i] + myans + r[i]);
        }
    }
};
