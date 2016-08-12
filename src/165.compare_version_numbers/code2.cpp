class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        while (i < version1.length() || j < version2.length()) {
            int v1 = 0;
            while (i < version1.length() && version1[i] != '.') {
                v1 *= 10;
                v1 += version1[i] - '0';
                i++;
            }
            int v2 = 0;
            while (j < version2.length() && version2[j] != '.') {
                v2 *= 10;
                v2 += version2[j] - '0';
                j++;
            }
            if (v1 > v2) return 1;
            if (v1 < v2) return -1;
            i++;
            j++;
        }
        return 0;
    }
};
