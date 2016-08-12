class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        for (int i = 0; i < haystack.length(); i++) {
            int flag = 1;
            if (i + needle.length() > haystack.length())
                flag = 0;
            for (int j = 0; flag && j < needle.length(); j++) {
                if (haystack[i + j] != needle[j])
                    flag = 0;
            }
            if (flag) return i;
        }
        return -1;
    }
};
