class Solution {
public:
    int ans = 0;
    vector<pair<int, int>> dir = {
        {-1,0},{1,0},   // up, down
        {0,-1},{0,1},   // left, right
    };
    void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<bool>>&visited, vector<pair<int,int>>& result){
        int rows = grid.size();
        int cols = grid[0].size();
        visited[row][col] = true;
        queue<pair<int, int>> q;
        q.push({row, col});
        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();
            result.push_back(curr);
            for(auto [dr, dc]: dir){
                int nr = dr + curr.first;// (0,0) -> (-1, 0) not a valid coordinate
                int nc = dc + curr.second; // (0,0) -> (0, -1) not valid same if row > rows or col >= cols
                if(nr < 0 || nc < 0 || nr >= rows || nc >= cols || grid[nr][nc] == '0')
                continue;
                else if(!visited[nr][nc] && grid[nr][nc] == '1'){
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int cols= grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(cols, false));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < cols; j++){
                vector<pair<int,int>> result;
                if(!visited[i][j] && grid[i][j] == '1'){
                    bfs(i, j, grid, visited, result);
                }
                if(result.size() > 0) ans++;
            }
        }
        return ans;
    }
};