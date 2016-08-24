class Solution {
public:
    int lengthLongestPath(string input) {
        int start = 0;
        int ans = 0;
        stack<int> s;
        int count = 1;
        s.push(-1);
        bool isFile = false;
        for (int i = 0; i <= input.length(); i++) {
            if (input[i] == '\n' || input[i] == 0) {
                while (s.size() > count) s.pop();
                int len = s.top() + 1 + i - start;
                s.push(len);
                if (isFile) ans = max(ans, len);
                isFile = false;
                count = 1;
                start = i + 1;
            } else if (input[i] == '\t') {
                count++;
                start = i + 1;
            } else if (input[i] == '.') {
                isFile = true;
            }
        }
        return ans;
    }
};
