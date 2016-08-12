class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows == 0) return ans;
        vector<int> myans;
        for (int i = 0; i < numRows; i++) {
            for (int j = myans.size() - 1; j > 0; j--) {
                myans[j] = myans[j - 1] + myans[j];
            }
            myans.push_back(1);
            ans.push_back(myans);
        }
        return ans;
    }
};
