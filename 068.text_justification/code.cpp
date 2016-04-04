class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        //if (words.size() == 1) return words;
        int begin = 0, end = 0;
        int width = 0;
        while (end < words.size()) {
            while (end < words.size()) {
                if (width + words[end].length() + 1 <= maxWidth + 1) {
                    width += words[end].length() + 1;
                    end++;
                } else break;
            }
            string myans;
            if (end == words.size()) {
                for (int i = end - 1; i > begin; i--) {
                    myans = " " + words[i] + myans;
                }
            } else {
                int len = maxWidth - width + end - begin;
                int count = end - begin - 1;
                for (int i = end - 1; i > begin; i--) {
                    myans = words[i] + myans;
                    for (int j = 0; j < len / count; j++) {
                        myans = " " + myans;
                    }
                    len -= len / count;
                    count--;
                }
            }
            myans = words[begin] + myans;
            while (myans.length() < maxWidth) {
                myans = myans + " ";
            }
            ans.push_back(myans);
            begin = end;
            width = 0;
        }
        return ans;
    }
};
