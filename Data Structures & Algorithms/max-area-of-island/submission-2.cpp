class Solution {
    int row;
    int col;
    vector<int> x;
    vector<int> y;
public:
    void initializeDirections(int rowSize, int colSize){
        x = {1,0,0,-1};
        y = {0,1,-1,0};
        this->row = rowSize;
        this->col = colSize;
    }
    bool isValidIndex(int x,int y){
        if(x<0 || y<0 || x>=this->row || y>=this->col) return false;
        return true;
    }
    int dfs(vector<vector<int>>& grid, int i,int j){
        grid[i][j] = 0;
        int area = 1;
        for(int dir=0;dir<4;dir++){
            int nextI = x[dir]+i;
            int nextJ = y[dir]+j;
            if(isValidIndex(nextI,nextJ) && grid[nextI][nextJ]==1){
                int currArea = dfs(grid,nextI,nextJ);
                area += currArea;
            }
        }

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        initializeDirections(grid.size(),grid[0].size());
        int area = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int currArea = dfs(grid,i,j);
                    area = max(area,currArea);
                }
            }

        }

        return area;
    }

};