#include<bits/stdc++.h>
using namespace std;
// # ── Phase 0: Graph Foundations — answer each in code below the comment ──

// # Q1. How do I build an adjacency LIST (dict[node] -> list[neighbor]) from an edge list?
// #     Write build_adj(n, edges, directed=False).
unordered_map<int, vector<int>> build_adj(vector<vector<int>>&edges, bool directed = false){
    unordered_map<int, vector<int>> adj_list;
    for(auto &edge : edges){
        int u = edge[0];
        int v = edge[1];
        adj_list[u].push_back(v);
        if(!directed)
        adj_list[v].push_back(u);
    }
    return adj_list;
}
// # Q2. How do I build an adjacency MATRIX (n×n) from the same edges?
// #     When does the matrix beat the list? (hint: dense graphs, O(1) edge lookup)

vector<vector<int>> build_matrix(int n, vector<vector<int>> &edges, bool directed = false){
    vector<vector<int>> matrix(n, vector<int> (n,0));

    for(auto &edge: edges){
        int u = edge[0];
        int v = edge[1];
        matrix[u][v] = 1;
        if(!directed) matrix[v][u] = 1;
    }
    return matrix;
}
// # Q3. What changes in my code when the graph is DIRECTED vs UNDIRECTED?
// #     (which lines do I add/remove when inserting an edge?)

// i have to just to make edge from u -> v and not other way, just in short i have to remove if and the statement inside the if. 

// # Q4. What changes when edges are WEIGHTED vs UNWEIGHTED?
// #     (what does each neighbor entry hold in each case?)
// make change in data structure 

unordered_map<int, vector<pair<int, int>>> adj_list_with_weight(vector<vector<int>> &weighted_edge, bool isDirected = false){
    unordered_map<int, vector<pair<int, int>>> weighted_list;
    for(auto &edge: weighted_edge){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        weighted_list[u].push_back({v, w});
        if(!isDirected) weighted_list[v].push_back({u, w});
    }
    return weighted_list;
}

// # Q5. How do I compute degree / in-degree / out-degree from my representation?
// #     How do self-loops and multi-edges affect those counts?

// for matrix representation.
pair<int, int> inDegreeAndOutDegreeInMatrix(vector<vector<int>> &adjMatrix, int node){
    int n = adjMatrix.size();
    int indegree = 0, outdegree = 0;
    for(int i = 0; i < n; i++){
        if(adjMatrix[i][node] == 1) indegree++;
    }
    for(int i = 0; i < n; i++){
        if(adjMatrix[node][i] == 1) outdegree++;
    }
    return {indegree, outdegree};
}

// for list representation of graph 
pair<int, int> inDegreeAndOutdegreeInList(unordered_map<int, vector<int>> &adjList, int node){
    // for outdegree i just need to calculate size of the vector corresponding of that node 
    // for in degree traverse each vector and search for the node passed in the function 
    int indegree = 0;
    int outdegree = adjList[node].size();

    for(auto &it : adjList){
        for(int neighbour: it.second){
            if(neighbour == node) indegree++;
        }
    }
    return {indegree, outdegree};
}

   // # Q6. Why is a GRID a graph? (cell = node, 4 or 8 neighbors = edges)
    // #     Write neighbors(r, c, rows, cols) that yields valid in-bounds neighbors.

vector<pair<int, int>> neighbours4Dir(int r, int c, int rows, int columns){
    vector<pair<int, int>> ans;
    vector<pair<int, int>> dir = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };
    for(auto [dr, dc]: dir){
        int nr = dr + r;
        int nc = dc + c;

        if(nr >= 0 && nr < rows && nc >= 0 && nc < columns)
        ans.push_back({nr, nc});
    }
    return ans;
}

vector<pair<int, int>> neighbours4Dir(int r, int c, int rows, int columns){
    vector<pair<int, int>> ans;
    vector<pair<int, int>> dir = {
        {-1, 0}, // up
        {1, 0}, // down 
        {0, -1}, // left
        {0, 1}, // right
        {-1, -1}, // top left
        {-1, 1}, // top right
        {1, 1}, // bottom right 
        {1, -1} // bottom left
    };
    for(auto [dr, dc]: dir){
        int nr = dr + r;
        int nc = dc + c;

        if(nr >= 0 && nr < rows && nc >= 0 && nc < columns)
        ans.push_back({nr, nc});
    }
    return ans;
}

int main(){
    int n = 5;
    vector<vector<int>> edges = {
        {0,1},
        {0,2},
        {0,3},
        {2,4}
    };
    auto adj = build_adj(edges);
    auto adjMatrix = build_matrix(edges);
    for(int i = 0; i < adjMatrix.size(); i++){
        auto indegreeAndOutdegree = inDegreeAndOutDegreeInMatrix(adjMatrix, i);
        cout << indegreeAndOutdegree.first << " "<< indegreeAndOutdegree.second << endl;
    }
    return 0;
}