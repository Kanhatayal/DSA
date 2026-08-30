class Solution {
  public:
    void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st){
        visited[u] = true;
        for(auto &neighbour: adj[u]){
            if(!visited[neighbour]) dfs(neighbour, adj, visited, st);
        }
        // last mai woh node dal rahe hai jaha se dfs marna start kiya tha kyuki jab pop krnge toh phle wahi element milega stack mai se 
        st.push(u);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> result;
        vector<bool> visited(V, false);
        stack<int> st;
        for(int i = 0; i < V; i++){
            if(!visited[i]) dfs(i, edges, visited, st);
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};