class Solution {
public:
    bool checkBipartite(int node, vector<vector<int>> &adj, vector<int>  &color, int currColor){
        color[node] = currColor;

        for(auto  &v: adj[node]){
            if(color[v] == color[node]) return false;

            if(color[v] == -1){
                int colorOfV = 1 - currColor;  // new thing to learn 0 hua toh 1 ya toh ulta iss statement se ho jaega 
                if(checkBipartite(v, adj, color, colorOfV) == false) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        int currColor = 0;
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(checkBipartite(i, graph, color, currColor) == false) return false;
            }
        }
        return true;
    }
};