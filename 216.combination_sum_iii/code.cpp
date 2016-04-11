class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> myans;
        makeCombination(myans, k, n);
        return ans;
    }
    void makeCombination(vector<int>& myans, int k, int n) {
        if (n == 0 && k == 0) {
            ans.push_back(myans);
            return;
        }
        if (n < 0) return;
        if (k > 0) {
            int start;
            if (myans.size() == 0) start = 1;
            else start = myans.back() + 1;
            for (int i = start; i < 10; i++) {
                myans.push_back(i);
                makeCombination(myans, k - 1, n - i);
                myans.pop_back();
            }
        }
    }
};
