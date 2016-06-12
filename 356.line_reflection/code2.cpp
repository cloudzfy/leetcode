class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        int N = points.size();
        if (N == 0) return true;
        unordered_map<int, unordered_set<int> > m;
        int smallest = INT_MAX, largest = INT_MIN;
        for (int i = 0; i < N; i++) {
            m[points[i].first].insert(points[i].second);
            smallest = min(smallest, points[i].first);
            largest = max(largest, points[i].first);
        }
        int sum = smallest + largest;
        for (int i = 0; i < N; i++) {
            int oppo = sum - points[i].first;
            if (m.find(oppo) != m.end() && m[oppo].find(points[i].second) != m[oppo].end()) continue;
            return false;
        }
        return true;
    }
};
