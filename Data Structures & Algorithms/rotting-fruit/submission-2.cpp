class Solution {
public:
    // enums 
    int ROTTEN = 2;
    int FRESH = 1;
    int EMPTY = 0;
    vector<int> x = {1,0,0,-1};
    vector<int> y = {0,-1,1,0};

    bool isValid(int currX,int currY,int row,int col){
        if(currX<0 || currY<0 || currX>=row || currY>=col) return false;
        return true;
    }

    void markRotten(vector<vector<int>>& grid,pair<int,int> &curr,int &goodCells,queue<pair<int,int>> &q){
        for(int dir=0;dir<4;dir++){
            int currX = curr.first + x[dir];
            int currY = curr.second + y[dir];
            if(isValid(currX,currY,grid.size(),grid[0].size()) && grid[currX][currY]==FRESH){
                grid[currX][currY] = ROTTEN;
                goodCells--;
                q.push({currX,currY});
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int emptyCell = 0;
        int rottenCells = 0;
        int goodCells = 0;

        queue<pair<int,int>> q;

        // find all rotten cells
        // do multi source bfs to find max time 
        // everytime a cell is marked rotten, also reduce goodCells
        // before return final maximum time -> check goodCells==0, yes, return maxCount, else -1

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==ROTTEN){
                    q.push({i,j});
                    rottenCells++;
                }else if(grid[i][j]==FRESH){
                    goodCells++;
                }else{
                    emptyCell++;
                }
            }
        }
        if(goodCells==0) return 0; // edge case, no oranges to rot, fastest way out 
        int timeLapsed = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int,int> front = q.front();
                q.pop();
                markRotten(grid,front,goodCells,q);
            }
            timeLapsed++;
        }
        return goodCells==0 ? timeLapsed-1 : -1;
    }
};
