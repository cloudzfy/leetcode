class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        int N = points.size();
        if (N == 0) return true;
        vector<pair<int, int> > points1 = points;
        vector<pair<int, int> > points2 = points;
        sort(points1.begin(), points1.end(), cmp1);
        sort(points2.begin(), points2.end(), cmp2);
        int mid = (points1[0].first + points2[0].first);
        if (N % 2 == 1 && points1[N / 2].first * 2 != mid) return false;
        for (int i = 0; i < N / 2; i++) {
            if (points1[i].first + points2[i].first != mid) return false;
            if (points1[i].second != points2[i].second) return false;
        }
        return true;
    }
    
    static bool cmp1(const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
    
    static bool cmp2(const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};
