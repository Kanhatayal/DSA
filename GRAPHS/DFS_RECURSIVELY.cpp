#include<bits/stdc++.h>
using namespace std;

void dfsRec(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &res){
    visited[node] = true;
    res.push_back(node);
    for(int adjs = 0; adjs < adj[node].size(); adjs++){
        if(!visited[adj[node][adjs]])
        dfsRec(adj[node][adjs], adj, visited, res);
    }
}
vector<int> dfs(vector<vector<int>> & adj){
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> res;
    // multi source dfs, use only single call for connected graph, loop is used for disconnected graph
    for(int i = 0; i < n; i++){
        if(!visited[i])
        dfsRec(i, adj, visited, res);
    }
    return res;
}
void addEdge(vector<vector<int>> &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    int v = 5;
    vector<vector<int>> adj(5);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 4);

    vector<int> res = dfs(adj);
    cout<<"dfs traversal of graph"<<endl;
    for(auto &i : res){
        cout<<i<<endl;
    }

    return 0;
}