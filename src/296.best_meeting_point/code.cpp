class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows = collectRows(grid);
        vector<int> cols = collectCols(grid);
        int row = rows[rows.size() / 2];
        int col = cols[cols.size() / 2];
        return getDistance(rows, row) + getDistance(cols, col);
    }
    
    vector<int> collectRows(vector<vector<int>>& grid) {
        vector<int> rows;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) rows.push_back(i);
            }
        }
        return rows;
    }
    
    vector<int> collectCols(vector<vector<int>>& grid) {
        vector<int> cols;
        for (int j = 0; j < grid[0].size(); j++) {
            for (int i = 0; i < grid.size(); i++) {
                if (grid[i][j]) cols.push_back(j);
            }
        }
        return cols;
    }
    
    int getDistance(vector<int>& points, int point) {
        int dist = 0;
        for (int i = 0; i < points.size(); i++) {
            dist += abs(points[i] - point);
        }
        return dist;
    }
};
