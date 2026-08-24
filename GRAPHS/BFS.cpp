#include<bits/stdc++.h>
using namespace std;

void bfsRec(int node, vector<vector<int>>&adj, vector<bool> &visited, vector<int> &res){
    queue<int> q;
    visited[node] = true;
    q.push(node);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        res.push_back(curr);
        for(auto &neighbour: adj[curr]){
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}
vector<int> bfs(vector<vector<int>> &adj){
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> res;
    // use loop for multi source bfs(remove loop for connected single graph)
    for(int i = 0; i < n; i++){
        if(visited[i] == false){
            bfsRec(i, adj, visited, res);
        }
    }
    // assuming, starting from 0th node, and node naming is from 0-> n-1
    bfsRec(0, adj, visited, res);
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

    vector<int> res = bfs(adj);
    cout<<"bfs traversal of graph"<<endl;
    for(auto &i : res){
        cout<<i<<endl;
    }

    return 0;
}