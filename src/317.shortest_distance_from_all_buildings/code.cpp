class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;
        vector<vector<int>> count(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        int buildings = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push(make_pair(i * m + j, 0));
                    while (!q.empty()) {
                        int pos = q.front().first;
                        int depth = q.front().second;
                        q.pop();
                        int x = pos / m;
                        int y = pos % m;
                        if (x - 1 >= 0 && grid[x - 1][y] == 0 && count[x - 1][y] == buildings) {
                            count[x - 1][y] = buildings + 1;
                            dist[x - 1][y] += depth + 1;
                            q.push(make_pair(pos - m, depth + 1));
                        }
                        if (x + 1 < n && grid[x + 1][y] == 0 && count[x + 1][y] == buildings) {
                            count[x + 1][y] = buildings + 1;
                            dist[x + 1][y] += depth + 1;
                            q.push(make_pair(pos + m, depth + 1));
                        }
                        if (y - 1 >= 0 && grid[x][y - 1] == 0 && count[x][y - 1] == buildings) {
                            count[x][y - 1] = buildings + 1;
                            dist[x][y - 1] += depth + 1;
                            q.push(make_pair(pos - 1, depth + 1));
                        }
                        if (y + 1 < m && grid[x][y + 1] == 0 && count[x][y + 1] == buildings) {
                            count[x][y + 1] = buildings + 1;
                            dist[x][y + 1] += depth + 1;
                            q.push(make_pair(pos + 1, depth + 1));
                        }
                    }
                    buildings++;
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (count[i][j] == buildings) {
                    ans = min(ans, dist[i][j]);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
