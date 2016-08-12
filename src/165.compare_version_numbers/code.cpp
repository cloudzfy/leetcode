class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        int num = 0;
        for (int i = 0; i < version1.size(); i++) {
            if (version1[i] == '.') {
                v1.push_back(num);
                num = 0;
                continue;
            }
            num = num * 10 + version1[i] - '0';
        }
        v1.push_back(num);
        num = 0;
        for (int i = 0; i < version2.size(); i++) {
            if (version2[i] == '.') {
                v2.push_back(num);
                num = 0;
                continue;
            }
            num = num * 10 + version2[i] - '0';
        }
        v2.push_back(num);
        for (int i = 0; i < v1.size() || i < v2.size(); i++) {
            int v1Num = i < v1.size() ? v1[i] : 0;
            int v2Num = i < v2.size() ? v2[i] : 0;
            if (v1Num > v2Num) return 1;
            else if (v1Num < v2Num) return -1;
        }
        return 0;
    }
};
