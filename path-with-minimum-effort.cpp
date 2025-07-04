class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int diff=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==n-1 && c==m-1)return diff;
            for(int i=0;i<4;i++){
                int nrow=delrow[i]+r;
                int ncol=delcol[i]+c;
                if(nrow>=0 && ncol>=0 && ncol<m && nrow<n ){
                    int currentEffort = abs(grid[r][c] - grid[nrow][ncol]);
                    int maxEffort = max(diff, currentEffort);
                    if(maxEffort<dist[nrow][ncol]){
                        dist[nrow][ncol]=maxEffort;
                        pq.push({maxEffort,{nrow,ncol}});
                    }
                }
            }

        }
        return -1;
        
    }
};
