class Solution {
// https://www.youtube.com/watch?v=amvrKlMLuGY
    vector<int> xCoordinate = {1,0,0,-1};
    vector<int> yCoordinate = {0,-1,1,0};
public:
    bool isValidIndex(int x,int y,int row,int col){
        if(x<0 || y<0 || x>=row || y >=col) return false;
        return true;
    }
    int swimInWater(vector<vector<int>>& grid) {
        // find a path where maximum elevation is minimized

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> visited(row,vector<bool> (col,false));
        visited[0][0] = true;

        // elevation_distance, node {x,y}
// Declaration:
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;

// Pushing:
minHeap.push({grid[0][0], {0, 0}});

        while(!minHeap.empty()){
            pair<int, pair<int,int>> top = minHeap.top();
            minHeap.pop();
            int maxElevationAtPar = top.first;
            pair<int,int> node = top.second;
            int currX = node.first;
            int currY = node.second;

            if(currX==row-1 && currY==col-1) return maxElevationAtPar;

            for(int i=0;i<4;i++){
                int nbrX = xCoordinate[i]+currX;
                int nbrY = yCoordinate[i]+currY;

                if(isValidIndex(nbrX,nbrY,row,col) && !visited[nbrX][nbrY]){
                    int maxWtAtNbr = max(grid[nbrX][nbrY],maxElevationAtPar);
                    minHeap.push({maxWtAtNbr,{nbrX,nbrY}});
                    visited[nbrX][nbrY] = true;
                }
            }

        }

        return -1;

    }
};
