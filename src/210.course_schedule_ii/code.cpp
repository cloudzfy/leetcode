class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> ans;
        for (int i = 0; i < prerequisites.size(); i++) {
            inDegree[prerequisites[i].first]++;
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            ans.push_back(course);
            for (int i = 0; i < graph[course].size(); i++) {
                inDegree[graph[course][i]]--;
                if (inDegree[graph[course][i]] == 0) q.push(graph[course][i]);
            }
        }
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i]) {
                ans.clear();
                return ans;
            }
        }
        return ans;
    }
};
