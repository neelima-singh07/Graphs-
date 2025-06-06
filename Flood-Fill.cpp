class Solution {
public:
    void dfs(vector<vector<int>>&grid,int row,int col,int color,int initial){
        int n=grid.size();
        int m=grid[0].size();
        
        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] != initial) {
            return;
        }
        //check for 4 directions 
        grid[row][col]=color;
        dfs(grid,row,col+1,color,initial);
        dfs(grid,row,col-1,color,initial);
        dfs(grid,row-1,col,color,initial);
        dfs(grid,row+1,col,color,initial);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>grid=image;
        int initial=grid[sr][sc];
        if (initial == color) return image;
        
        dfs(grid,sr,sc,color,initial);
        return grid;
        
        
    }
};

//They way striver did 
class Solution {
public:
    void dfs(vector<vector<int>>&grid,int row,int col,int color,int initial){
        grid[row][col]=color;
        int n=grid.size();
        int m=grid[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==initial){
                
                dfs(grid,nrow,ncol,color,initial);
            }
        }
        
        

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>grid=image;
        int initial=grid[sr][sc];
        if (initial == color) return image;
        
        dfs(grid,sr,sc,color,initial);
        return grid;
        
        
    }
};



//using BFS Traversal 
class Solution {
public:
    void dfs(vector<vector<int>>&grid,int row,int col,int color,int initial,vector<vector<int>>&vis){
        grid[row][col]=color;
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==initial && vis[nrow][ncol]!=1){
                    grid[nrow][ncol]=color;
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        
        
        

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>grid=image;
        int initial=grid[sr][sc];
        if (initial == color) return image;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        dfs(grid,sr,sc,color,initial,vis);
        return grid;
        
        
    }
};
