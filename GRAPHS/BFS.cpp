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
    for(int i = 0; i < n; i++){
        if(visited[i] == false){
            bfsRec(i, adj, visited, res);
        }
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

    vector<int> res = bfs(adj);
    cout<<"bfs traversal of graph"<<endl;
    for(auto &i : res){
        cout<<i<<endl;
    }

    return 0;
}

// # ── Phase 1: Traversal — answer each in code below the comment ──

// # Q1. How do I write DFS both RECURSIVELY and ITERATIVELY (explicit stack)?
// #     What single structure stops infinite loops on cycles, and WHEN do I mark a node?
// #     (invariant: a node is pushed/visited only once — the visited set is the guard)

// # Q2. How do I write BFS with a queue?
// #     WHY does BFS give shortest paths on UNWEIGHTED graphs?
// #     (invariant: the queue always holds nodes in non-decreasing distance order)

// # Q3. How do I traverse a DISCONNECTED graph so I miss no node?
// #     (loop over all nodes, launch a fresh traversal from each unvisited one)

// # Q4. Practice: print a graph's DFS and BFS order from an edge list I built myself.

// # Q5. ★ Clone Graph (Med): what map do I need so a back-edge finds the copy
// #     instead of recursing forever?
// #     (invariant: old node -> new node, built as you visit)