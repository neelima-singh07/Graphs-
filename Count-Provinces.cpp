class Solution {
public:
    void dfs(int st,vector<vector<int>>& adjl,vector<int>&vis){
        vis[st]=1;
        for(auto it:adjl[st]){
            if(vis[it]!=1){
                dfs(it,adjl,vis);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<vector<int>>adjl(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j]==1 && i!=j){
                    adjl[i].push_back(j);
                    adjl[j].push_back(i);

                }
                
            }
        }

        
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]!=1){
                cnt++;
                dfs(i,adjl,vis);
            }
        }
        return cnt;
        
    }
};
