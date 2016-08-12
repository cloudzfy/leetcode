class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        ans.push_back(0);
        int count = 0;
        int len = ans.size();
        int index = 0;
        while (count < num) {
            if (index == len) {
                len = ans.size();
                index = 0;
            }
            ans.push_back(ans[index] + 1);
            index++;
            count++;
        }
        return ans;
    }
};
