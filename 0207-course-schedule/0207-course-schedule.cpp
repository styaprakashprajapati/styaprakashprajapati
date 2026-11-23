class Solution {
public:
    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto &p : prerequisites) {

            int course = p[0];
            int pre = p[1];

            adj[pre].push_back(course);

            indegree[course]++;
        }

        queue<int> q;

        // Add courses having indegree 0
        for (int i = 0; i < numCourses; i++) {

            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        // BFS
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            count++;

            for (int neighbor : adj[node]) {

                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Check if all courses completed
        return count == numCourses;
    }
};