class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string ans;
        int len = path.length();
        if (len == 0) return ans;
        int start, end;
        for (int i = 0; i < len; i++) {
            if (i > 0 && path[i] != '/' && path[i - 1] == '/') {
                start = i - 1;
            }
            if (path[i] != '/' && ((i + 1 < len && path[i + 1] == '/') || (i == len - 1))) {
                end = i;
                string tmp = path.substr(start, end - start + 1);
                if (tmp == "/.") continue;
                else if (tmp == "/..") {
                    if (!s.empty()) s.pop();
                }
                else {
                    s.push(tmp);
                }
            }
        }
        while(!s.empty()) {
            ans = s.top() + ans;
            s.pop();
        }
        if (ans == "") ans = "/";
        return ans;
    }
};
