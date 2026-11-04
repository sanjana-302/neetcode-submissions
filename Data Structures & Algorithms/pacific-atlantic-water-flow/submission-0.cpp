class Solution {
public:
    vector<int> xDir = {1,0,0,-1};
    vector<int> yDir = {0,-1,1,0};
    int row ;
    int col ;
    string PACIFIC = "Pacific"; 
    string ATLANTIC = "Atlantic";
    void setRowSize(int n){
        this->row = n;
    }
    void setColSize(int n){
        this->col = n;
    }
    queue<vector<int>> prepQueueForOcean(const vector<vector<int>>& heights, string oceanType) {
        int m = heights.size();
        int n = heights[0].size();
        
        queue<vector<int>> q;

        if (oceanType == "Pacific") {
            // 1. Add the top row (all columns in row 0)
            for (int c = 0; c < n; ++c) {
                q.push({0, c});
            }
            // 2. Add the left column (all rows in column 0, skipping {0,0} to avoid duplicate)
            // Note: Duplicates in a BFS queue are fine because of your visited matrix, 
            // but starting from r = 1 is a clean optimization.
            for (int r = 1; r < m; ++r) {
                q.push({r, 0});
            }
        } 
        else if (oceanType == "Atlantic") {
            // 1. Add the bottom row (all columns in row m - 1)
            for (int c = 0; c < n; ++c) {
                q.push({m - 1, c});
            }
            // 2. Add the right column (all rows in column n - 1)
            for (int r = 0; r < m - 1; ++r) {
                q.push({r, n - 1});
            }
        }

        return q;
    }
    bool isValid(int x,int y,int row,int col){
        if(x<0 || y<0 || x>=row || y>=col) return false;
        return true;
    }
    set<vector<int>> bfs(vector<vector<int>>& heights,queue<vector<int>> &q){
        set<vector<int>> visited;
        set<vector<int>> s;
        while(!q.empty()){
            vector<int> front = q.front();
            s.insert(front); // insert in result
            visited.insert(front); // insert in lookup set
            q.pop();
            int x = front[0];
            int y = front[1];
            for(int i=0;i<4;i++){
                int currX = x + xDir[i];
                int currY = y + yDir[i];
                // evaluate adjacent vertices
                if(isValid(currX,currY,row,col) && visited.find({currX,currY})==visited.end() && heights[currX][currY]>=heights[x][y]){
                    q.push({currX,currY});
                }
            }
        }

        return s;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // from every cell -> explore all paths towards two boundaries, if satisfied good.
        // for reducing complexity 
        // - consider having 2 bfs traversals 
        // - find intersection of both results 
        setRowSize(heights.size());
        setColSize(heights[0].size());
        queue<vector<int>> q;
        // better way to have interface for queue preperation
        q = prepQueueForOcean(heights,PACIFIC);
        set<vector<int>> pacific = bfs(heights,q);
        q = prepQueueForOcean(heights,ATLANTIC);
        set<vector<int>> atlantic = bfs(heights,q);
        vector<vector<int>> result;

        for(const vector<int> &v : pacific){
            if(atlantic.find(v)!=atlantic.end()){
                result.push_back(v);
            }
        }

        return result;
    }
};
