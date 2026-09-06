class Solution {
public:

void addEdge(vector<vector<int>> &adj, int u, int v) { adj[v].push_back(u); }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            addEdge(adj, prerequisites[i][0], prerequisites[i][1]);
        }
        vector<int> indegree(numCourses, 0);
        vector<int> orderOfCourses;
        for(int i = 0; i < adj.size(); i++){
            for(auto &neighbor: adj[i]) indegree[neighbor]++;
        }
        queue<int> q; 
        // push all nodes with zero indegree
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int curr = q.front();
            orderOfCourses.push_back(curr);
            q.pop();
            for(auto &v: adj[curr]){
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        if(orderOfCourses.size() == numCourses) return orderOfCourses;

        return {};
    }
};