class Solution {
public:
    void makeList(vector<vector<int>> & isConnected, int n, vector<vector<int>> &adj){
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(isConnected[i][j] == 1){
                    int u = i; 
                    int v = j;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // make list using 
        int n = isConnected.size();
        vector<vector<int>> adjList(n);
        makeList(isConnected, n, adjList);

        vector<bool> visited(n, false);
        queue<int> q;
        int numberOfProvinces = 0;
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            q.push(i);
            visited[i] = true;  
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                for(auto &nbhr: adjList[curr]){
                    if(!visited[nbhr]){
                        visited[nbhr] = true;
                        q.push(nbhr);
                    }
                }
            }
            numberOfProvinces++;
        } 
        return numberOfProvinces;
    }
};