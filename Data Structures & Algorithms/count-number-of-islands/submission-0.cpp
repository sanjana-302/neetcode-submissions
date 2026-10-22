class Solution {
private:
    vector<int> x;
    vector<int> y;
    int row;
    int col;
    int dir = 4;
public:

    void initializeDirections(int row,int col){
        x = {-1,0,0,1};
        y = {0,-1,1,0};
        this->row = row;
        this->col = col;
    }

    bool validIndex(int x,int y){
        if(x<0 || y<0 || x>=row || y>=col) return false;
        return true;
    }

    void dfs(vector<vector<char>>& grid, int i,int j){
        grid[i][j] = '0';

        for(int d=0;d<dir;d++){
            int currX = x[d] + i;
            int currY = y[d] + j;
            if(validIndex(currX,currY) && grid[currX][currY]=='1'){
                dfs(grid,currX,currY);
            }
        }

        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        initializeDirections(row,col);

        int count = 0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }

        return count;
    }
};
