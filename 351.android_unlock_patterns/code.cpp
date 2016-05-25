class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int visited = 0;
        int ans = 0;
        ans += check(visited, 0, 0, 1, m, n) * 4;
        ans += check(visited, 0, 1, 1, m, n) * 4;
        ans += check(visited, 1, 1, 1, m, n);
        return ans;
    }
    
    int check(int &visited, int x, int y, int count, int m, int n) {
        if (count == n) return 1;
        int myans = 0;
        if (count >= m) myans++;
        visited += 1 << (x * 3 + y);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!(visited & (1 << (i * 3 + j)))) {
                    if (abs(x - i) == 2 && abs(y - j) == 2 && !(visited & (1 << 4))) continue;
                    if (abs(x - i) == 2 && y == j && !(visited & (1 << (3 + y)))) continue;
                    if (abs(y - j) == 2 && x == i && !(visited & (1 << (3 * x + 1)))) continue;
                    myans += check(visited, i, j, count + 1, m, n);
                }
            }
        }
        visited -= 1 << (x * 3 + y);
        return myans;
    }
};
