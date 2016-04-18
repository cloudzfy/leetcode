/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if (n < 3) return n;
        int ans = 0;
        unordered_map<string, int> m;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            m.clear();
            int isSame = 0, myans = 0;
            for (int j = 0; j < n; j++) {
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    visited[j] = true;
                    isSame++;
                    continue;
                }
                int deltaX = points[j].x - points[i].x;
                int deltaY = points[j].y - points[i].y;
                int sign = deltaX * deltaY < 0 ? -1 : 1;
                deltaX = abs(deltaX);
                deltaY = abs(deltaY);
                int r = gcd(deltaX, deltaY);
                deltaX = r ? deltaX / r : deltaX;
                deltaY = r ? deltaY / r : deltaY;
                string slope = slopeToStr(deltaX, deltaY, sign);
                myans = max(myans, ++m[slope]);
            }
            ans = max(ans, myans + isSame);
        }
        return ans;
    }
    int gcd(int a, int b) {
        if (a < b) swap(a, b);
        while (b) {
            int r = b;
            b = a % b;
            a = r;
        }
        return a;
    }
    string slopeToStr(int x, int y, int sign) {
        char str[50];
        if (sign == 1) sprintf(str, "%d/%d", y, x);
        else sprintf(str, "-%d/%d", y, x);
        return str;
    }
};
