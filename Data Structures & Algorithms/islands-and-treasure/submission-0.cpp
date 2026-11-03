class Solution {
public:
    int LAND = 2147483647;
    int WATER = -1;
    int PRIZE = 0;
    vector<int> x;
    vector<int> y;
    int row;
    int col;
    int DIR_COUNT = 4;

    void initializeDirections(int row, int col){
        x = {1,0,0,-1};
        y = {0,-1,1,0};
        this->row = row;
        this->col = col;
    }

    bool validIndex(int i,int j){
        if(i<0 || j<0 || i>=row || j>=col) return false;
        return true;
    }
    void populateNextLevel(pair<int,int> curr,vector<vector<int>>& grid,queue<pair<int,int>> &q,int level){
        for(int dir=0;dir<DIR_COUNT;dir++){
            int nextX = x[dir] + curr.first;
            int nextY = y[dir] + curr.second;
            if(validIndex(nextX,nextY) && grid[nextX][nextY]==LAND){
                grid[nextX][nextY] = level;
                q.push({nextX,nextY});
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // first line of thought
        // 100*100 = 10000
        // 10000*10000 = 10^8 -> (m*n)^2

        // let's go with multi source bfs
        initializeDirections(grid.size(),grid[0].size());
        queue<pair<int,int>> q;

        // populate starting nodes
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==PRIZE){
                    q.push({i,j});
                }
            }
        }
        int level = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int,int> curr = q.front();
                q.pop();
                populateNextLevel(curr,grid,q,level);
            }
            level++;
        }

        return; 
    }
};
