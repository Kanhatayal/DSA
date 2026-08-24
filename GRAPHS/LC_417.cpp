class Solution {
public:
    vector<vector<int>> directions = {
        {1, 0},
        {-1, 0},
        {0, -1},
        {0, 1}
    };
    void DFS(vector<vector<int>>& heights, int i, int j, int prevCellValue, vector<vector<bool>>& visited){
        if(i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size() || heights[i][j] < prevCellValue || visited[i][j])
        return;

        visited[i][j] = true;
        for(auto &dir : directions){
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            
            DFS(heights, i_, j_, heights[i][j], visited);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacificVisited(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlanticVisited(rows, vector<bool>(cols, false));
        
        vector<vector<int>> ans;

        for(int i = 0; i < cols; i++){
            DFS(heights, 0, i, INT_MIN, pacificVisited);
            DFS(heights, rows-1, i, INT_MIN, atlanticVisited);
        }

        for(int j = 0; j < rows; j++){
            DFS(heights, j, 0, INT_MIN, pacificVisited);
            DFS(heights, j, cols-1, INT_MIN, atlanticVisited);
        }
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(pacificVisited[i][j] && atlanticVisited[i][j])
                ans.push_back({i,j});
            }
        }
        return ans;
    }
};