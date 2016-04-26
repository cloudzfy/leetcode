class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size();
        if (n == 0) return;
        int m = rooms[0].size();
        if (m == 0) return;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rooms[i][j] == 0) {
                    visited[i][j] = true;
                    q.push(make_pair(i, j));
                }
            }
        }
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int dist = rooms[x][y];
            if (x - 1 >= 0 && !visited[x - 1][y] && rooms[x - 1][y] != -1) {
                rooms[x - 1][y] = min(rooms[x - 1][y], dist + 1);
                if (!visited[x - 1][y]) q.push(make_pair(x - 1, y));
                visited[x - 1][y] = true;
            }
            if (x + 1 < n && !visited[x + 1][y] && rooms[x + 1][y] != -1) {
                rooms[x + 1][y] = min(rooms[x + 1][y], dist + 1);
                if (!visited[x + 1][y]) q.push(make_pair(x + 1, y));
                visited[x + 1][y] = true;
            }
            if (y - 1 >= 0 && !visited[x][y - 1] && rooms[x][y - 1] != -1) {
                rooms[x][y - 1] = min(rooms[x][y - 1], dist + 1);
                if (!visited[x][y - 1]) q.push(make_pair(x, y - 1));
                visited[x][y - 1] = true;
            }
            if (y + 1 < m && !visited[x][y + 1] && rooms[x][y + 1] != -1) {
                rooms[x][y + 1] = min(rooms[x][y + 1], dist + 1);
                if (!visited[x][y + 1]) q.push(make_pair(x, y + 1));
                visited[x][y + 1] = true;
            }
        }
    }
};
