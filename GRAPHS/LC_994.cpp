class Solution {
public:
    typedef pair<int,int> p;
    vector<vector<int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int freshOranges = 0;
        queue<p> q;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1) freshOranges++;
                else if(grid[i][j] == 2) q.push({i,j});
            }
        }
        if(freshOranges == 0) return 0;

        int minutes = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                p curr = q.front();
                q.pop();

                int i = curr.first;
                int j = curr.second;
                  
                for(auto &dir: directions){
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];
                    if(i_ >= 0 && i_ < rows && j_ >= 0 && j_ < cols && grid[i_][j_] == 1){
                        grid[i_][j_] = 2; 
                        q.push({i_, j_});
                        freshOranges--;
                    }
                }
            }
            if(!q.empty())
            minutes++;
        }
        return freshOranges == 0? minutes : -1;
    }
};