class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>&vis,int row,int col){
        vis[row][col]=1;
        int m=grid.size();
        int n=grid[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && vis[nrow][ncol]!=1 && grid[nrow][ncol]==1){
                vis[nrow][ncol]=1;
                dfs(grid,vis,nrow,ncol);
            }

        }

    }
    int numEnclaves(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>grid=matrix;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                dfs(grid,vis,i,0);
            }
            
        }
        for(int i=0;i<n;i++){
            if(grid[0][i]==1){
                dfs(grid,vis,0,i);
            }
            
        }
        for(int i=0;i<m;i++){
            if(grid[i][n-1]==1){
                dfs(grid,vis,i,n-1);
            }
            
        }
        for(int i=0;i<n;i++){
            if(grid[m-1][i]==1){
                dfs(grid,vis,m-1,i);
            }
            
        }
        int cnt=0;
        //traverse again to find unvisited and 1's 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]!=1)cnt++;
            }
        }
        return cnt;



        
    }
};
