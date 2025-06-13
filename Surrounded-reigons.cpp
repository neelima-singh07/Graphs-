class Solution {
public:
    void dfs(vector<vector<char>>&board,vector<vector<int>>&vis,int row,int col){
        vis[row][col]=1;
        int m=board.size();
        int n=board[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && vis[nrow][ncol]!=1 && board[nrow][ncol]=='O'){
                vis[nrow][ncol]=1;
                dfs(board,vis,nrow,ncol);
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        vector<vector<char>>grid=board;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            if(board[0][j]=='O'){
                dfs(board,vis,0,j);
            }
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                dfs(board,vis,i,0);
            }
        }
        for(int j=0;j<n;j++){
            if(board[m-1][j]=='O'){
                dfs(board,vis,m-1,j);
            }

        }
        for(int i=0;i<m;i++){
            if(board[i][n-1]=='O'){
                dfs(board,vis,i,n-1);
            }

        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && vis[i][j]!=1){
                    board[i][j]='X';
                }
            }
        }
        
        
    }
};
