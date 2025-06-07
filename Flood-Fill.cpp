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
