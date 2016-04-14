class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>(0));
        for (int i = 0; i < prerequisites.size(); i++) {
            inDegree[prerequisites[i].second]++;
            graph[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        queue<int> q;
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int i = 0; i < graph[node].size(); i++) {
                inDegree[graph[node][i]]--;
                if (inDegree[graph[node][i]] == 0) q.push(graph[node][i]);
            }
        }
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i]) return false;
        }
        return true;
    }
};
