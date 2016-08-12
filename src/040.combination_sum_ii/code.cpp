class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> myans;
        sort(candidates.begin(), candidates.end());
        makeSum(candidates, target, 0, myans);
        return ans;
    }
    void makeSum(vector<int>& candidates, int target, int index, vector<int>& myans) {
        if (target == 0) {
            ans.push_back(myans);
            return;
        }
        if (index >= candidates.size()) return;
        int nextIndex = index + 1;
        while (candidates[nextIndex] == candidates[nextIndex - 1]) nextIndex++;
        if (nextIndex > candidates.size()) nextIndex = candidates.size();
        makeSum(candidates, target, nextIndex, myans);
        int count = 0;
        for (int i = index; i < nextIndex && target - candidates[index] >= 0; i++) {
            count++;
            target -= candidates[index];
            myans.push_back(candidates[index]);
            makeSum(candidates, target, nextIndex, myans);
        }
        for (int i = 0; i < count; i++) {
            myans.pop_back();
        }
    }
};
