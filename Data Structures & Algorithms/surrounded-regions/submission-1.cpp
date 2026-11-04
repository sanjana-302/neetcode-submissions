class Solution {
public:
    vector<int> xDir = {1,0,0,-1};
    vector<int> yDir = {0,-1,1,0};
    bool isValid(int x,int y,int row,int col){
        if(x<0 || y<0 || x>=row || y>=col) return false;
        return true;
    }
    queue<vector<int>> findAllBorderZeros(vector<vector<char>>& board){
        queue<vector<int>> q;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='X') continue;
                if(i==0 || i==board.size()-1){
                    q.push({i,j});
                }
                if(j==0 || j==board[0].size()-1){
                    q.push({i,j});
                }
            }
        }

        return q;
    }
    void solve(vector<vector<char>>& board) {
        // find out free regions and mark whatever is remaing 
        // bfs queue -> include all border items 
        // prepare a set of items that are connected to border regions 
        // mark all reamining items 
        queue<vector<int>> q = findAllBorderZeros(board); // keep coordinates

        int row = board.size();
        int col = board[0].size();


        vector<vector<bool>> visited(row,vector<bool> (col,false)); // is this cell free?
        while(!q.empty()){
            vector<int> front = q.front();
            q.pop();
            int x = front[0];
            int y = front[1];
            visited[x][y] = true;
            for(int i=0;i<4;i++){
                int currX = x+xDir[i];
                int currY = y+yDir[i];

                if(isValid(currX,currY,row,col) && visited[currX][currY]==false && board[currX][currY]=='O'){
                    q.push({currX,currY});
                }
            }

        }

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O' && visited[i][j] == false){
                    board[i][j]='X';
                }
            }
        }

        return;
    }
};
