class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        // calculate indegree of every nodes first 
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++){
            for(auto &v : edges[i]) indegree[v]++;
        }
        // push all the nodes whose indegree is 0
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0) q.push(i);
        }
        // apply bfs on nodes in queue and reduce indegree of all the neighbours 
        vector<int> result;
        while(!q.empty()){
            int curr = q.front();
            result.push_back(curr);
            q.pop();
            
            for(auto &nbhr: edges[curr]){
                indegree[nbhr]--;
                if(indegree[nbhr] == 0) q.push(nbhr);
            }
        }
        return result;
    }
};