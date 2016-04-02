class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> myans;
        makeSum(candidates, target, 0, myans);
        return ans;
    }
    void makeSum(vector<int>& candidates, int target, int index, vector<int> &myans) {
        if (target == 0) {
            ans.push_back(myans);
            return;
        }
        if (index >= candidates.size()) return;
        makeSum(candidates, target, index + 1, myans);
        for (int k = 1; k * candidates[index] <= target; k++) {
            myans.push_back(candidates[index]);
            makeSum(candidates, target - k * candidates[index], index + 1, myans);
        }
        for (int k = 1; k * candidates[index] <= target; k++) {
            myans.pop_back();
        }
    }
};
