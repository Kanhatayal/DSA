#include<bits/stdc++.h>
using namespace std;

vector<int> dfs(vector<vector<int>> &adj){
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> res;
    stack<int> st;
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        st.push(i);
        while(!st.empty()){
            int node = st.top();
            st.pop();

            if(!visited[node]){
                visited[node] = true;
                res.push_back(node);
                // due to lifo property of stack we are taking it in reverse, and if we notice 
                // for every node we are exploring their connected nodes are getting printed in reverse
                
                // example
                // 0 -> 2, 3, 1
                // after dfs visit
                // 0 2 4 3 1
                for(int j = adj[node].size() - 1; j >= 0; j--){
                    int nbhr  = adj[node][j];
                    if(!visited[nbhr]) st.push(nbhr);
                }
            }
        }
    }
    return res;
}
void addEdge(vector<vector<int>>& adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    int v = 5;
    vector<vector<int>> adj(v);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    vector<int> ans = dfs(adj);
    cout<<"dfs travsersal of graph iteratively"<<endl;
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}