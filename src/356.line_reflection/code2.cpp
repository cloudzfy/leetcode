class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        int N = points.size();
        if (N == 0) return true;
        set<pair<int, int> > m;
        int smallest = INT_MAX, largest = INT_MIN;
        for (int i = 0; i < N; i++) {
            m.insert(points[i]);
            smallest = min(smallest, points[i].first);
            largest = max(largest, points[i].first);
        }
        int sum = smallest + largest;
        for (int i = 0; i < N; i++) {
            if (m.find(make_pair(sum - points[i].first, points[i].second)) == m.end()) return false;
        }
        return true;
    }
};
