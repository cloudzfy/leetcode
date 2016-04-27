class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> getFactors(int n) {
        if (n == 1) return ans;
        vector<int> myans;
        getFactors(n, 2, n, myans);
        return ans;
    }
    void getFactors(int n, int begin, int end, vector<int>& myans) {
        for (int i = begin; i * i <= n; i++) {
            if (n % i == 0) {
                myans.push_back(i);
                getFactors(n / i, i, end, myans);
                myans.pop_back();
            }
        }
        if (myans.size() > 0) {
            myans.push_back(n);
            ans.push_back(myans);
            myans.pop_back();
        }
    }
};
