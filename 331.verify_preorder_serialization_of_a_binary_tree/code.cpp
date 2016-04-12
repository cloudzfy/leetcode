class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> s;
        int start = 0;
        for (int i = 0; i <= preorder.length(); i++) {
            string elem;
            if (preorder[i] == ',' || preorder[i] == 0) {
                elem = preorder.substr(start, i - start);
                start = i + 1;
            } else continue;
            s.push_back(elem);
            while (s.size() >= 3) {
                int len = s.size();
                if (s[len - 1] == "#" && s[len - 2] == "#" && s[len - 3] != "#") {
                    s.pop_back();
                    s.pop_back();
                    s.pop_back();
                    s.push_back("#");
                } else break;
            }
        }
        return (s.size() == 1 && s[0] == "#");
    }
};
