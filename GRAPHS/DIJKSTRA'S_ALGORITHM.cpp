    class Solution {
      public:
        void makeList(vector<vector<pair<int, int>>> &adj, int u, int v, int wt){
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
            // Code here
            
            // make adj list 
            vector<vector<pair<int, int>>> adj(V);
            for(int i = 0; i < edges.size(); i++){
                makeList(adj, edges[i][0], edges[i][1], edges[i][2]);
            }
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            vector<int> result(V, INT_MAX);
            
            result[src] = 0;
            pq.push({0, src}); // {dist, node jaha jana hai} toh 2 se 2 pe 0 distance aaega 
            while(!pq.empty()){
                int d = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                if (d > result[node]) continue; // to skip outdated entries from priority queue
                
                for(auto &vec: adj[node]){
                    int adjNode = vec.first;
                    int wt      = vec.second;
                    
                    if(d+wt < result[adjNode]){
                        result[adjNode] = d + wt;
                        pq.push({d + wt, adjNode});
                    }
                }
            }
            return result;
        }
    };