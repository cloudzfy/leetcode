class Solution {
private:
    map<char, string> dict;
    vector<string> ans;
public:
    vector<string> letterCombinations(string digits) {
        dict['2'] = "abc";
        dict['3'] = "def";
        dict['4'] = "ghi";
        dict['5'] = "jkl";
        dict['6'] = "mno";
        dict['7'] = "pqrs";
        dict['8'] = "tuv";
        dict['9'] = "wxyz";
        if (digits.size() > 0) {
            dfs(digits, 0, "");
        }
        return ans;
    }
    void dfs(string digits, int depth, string myans) {
        if (depth == digits.size()) {
            ans.push_back(myans);
        }
        for (int i = 0; i < dict[digits[depth]][i] != 0; i++) {
            dfs(digits, depth + 1, myans + dict[digits[depth]][i]);
        }
    }
};
