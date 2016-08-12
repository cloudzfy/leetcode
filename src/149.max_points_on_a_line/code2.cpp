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
        if (points.size() == 0) return 0;
        map<pair<int, int>, int> m;
        int ans = 1;
        for (int i = 0; i < points.size(); i++) {
            m.clear();
            int count = 1;
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                int x = points[j].x - points[i].x;
                int y = points[j].y - points[i].y;
                if (x == 0 && y == 0) {
                    count++;
                    continue;
                }
                if (y < 0) {
                    y = -y;
                    x = -x;
                }
                int r = gcd(x, y);
                x /= r;
                y /= r;
                m[make_pair(x, y)]++;
            }
            for (auto it = m.begin(); it != m.end(); it++) {
                ans = max(ans, it->second + count);
            }
            ans = max(ans, count);
        }
        return ans;
    }
    
    int gcd(int x, int y) {
        while (y) {
            int tmp = x % y;
            x = y;
            y = tmp;
        }
        return x;
    }
};
