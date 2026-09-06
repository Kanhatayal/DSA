// kahn's algorigthm, because this algorithm inherently checks the cyclicity of directed graph 
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build Adjacency List and Indegree array
        for (auto& edge : prerequisites) {
            int course = edge[0];
            int prereq = edge[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            result.push_back(curr);

            for (int neighbor : adj[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (result.size() == numCourses) {
            return true;
        }
        return false;
    }
};