//way 1 using BFS Traversal which is good and more efficent 
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        if(n==1 && grid[0][0]==0)return 1;
        if(n==1 && grid[0][0]==1)return -1;
        if(grid[0][0]==1)return -1;
        vector<vector<int>>vis(n,vector<int>(n,0));
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});
        vis[0][0]=1;
        
        int delrow[] = {-1, -1,  0, 1, 1,  1,  0, -1};
        int delcol[] = { 0,  1,  1, 1, 0, -1, -1, -1};
        while(!q.empty()){
            int r=q.front().second.first;
            int c=q.front().second.second;
            int d=q.front().first;
            q.pop();
            for(int i=0;i<8;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0 && ncol>=0 && ncol<n && nrow<n && vis[nrow][ncol]!=1 && grid[nrow][ncol]==0){
                    q.push({d+1,{nrow,ncol}});
                    vis[nrow][ncol]=1;
                    if(nrow==n-1 && ncol==n-1){
                        return d+2;
                    }

                }
            }
            

            

        }
        return -1;


        
    }
};



//way 2 using DIjkstra Algo
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if(source==destination)return 0;
        queue<pair<int,pair<int,int>>>q;
        int src_row=source.first;
        int src_col=source.second;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        q.push({0,{src_row,src_col}});
        dist[src_row][src_col]=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().second.first;
            int c=q.front().second.second;
            int d=q.front().first;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && dist[nrow][ncol]!=0 && grid[nrow][ncol]!=0 && ((d+1)<dist[nrow][ncol]) ){
                    dist[nrow][ncol]=d+1;
                    
                    q.push({d+1,{nrow,ncol}});
                    if(nrow==destination.first && ncol==destination.second)return d+1;
                    
                }
            }    
        }
        return -1;
    }
