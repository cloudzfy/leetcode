class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans;
        for(int i = 0; i < strs.size(); i++) {
            ans.append(to_string(strs[i].length()) + " " + strs[i]);
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while (i < s.length()) {
            int num;
            sscanf(&s[i], "%d", &num);
            while (s[i] != ' ') i++;
            ans.push_back(s.substr(i + 1, num));
            i = i + 1 + num;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
