class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for (int j = 0; j < left.size(); j++) {
                    for (int k = 0; k < right.size(); k++) {
                        if (input[i] == '+') ans.push_back(left[j] + right[k]);
                        else if (input[i] == '-') ans.push_back(left[j] - right[k]);
                        else ans.push_back(left[j] * right[k]);
                    }
                }
            }
        }
        if (ans.size() == 0) ans.push_back(strToNum(input));
        return ans;
    }
    int strToNum(string s) {
        int num;
        sscanf(&s[0], "%d", &num);
        return num;
    }
};
