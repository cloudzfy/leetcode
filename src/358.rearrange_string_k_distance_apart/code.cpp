struct letter {
    char ch;
    int frequency;
    letter(char ch, int frequency) : ch(ch), frequency(frequency) {}
};

struct cmp {
    bool operator()(const letter &a, const letter &b) {
        return a.frequency < b.frequency;
    }
};
class Solution {
public:
    string rearrangeString(string str, int k) {
        unordered_map<char, int> m;
        priority_queue<letter, vector<letter>, cmp> pq;
        for (int i = 0; i < str.length(); i++) {
            m[str[i]]++;
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            pq.push(letter(it->first, it->second));
        }
        int len = str.length();
        string ans(len, '1');
        int idx = 0;
        while (!pq.empty()) {
            char ch = pq.top().ch;
            int f = pq.top().frequency;
            pq.pop();
            for (int i = 0; i < f; i++) {
                while (ans[idx] != '1') {
                    if (idx + 1 < len) idx++;
                    else idx = 0;
                }
                ans[idx] = ch;
                if (i + 1 < f) idx += k;
            }
            if (!check(ans, ch, k)) return "";
        }
        return ans;
    }
    
    bool check(string s, char ch, int k) {
        int mark = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ch) {
                if (mark != -1 && i - mark < k) return false;
                mark = i;
            }
        }
        return true;
    }
};
