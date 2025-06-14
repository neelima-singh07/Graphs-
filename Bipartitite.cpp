class Solution {
public:
    bool  dfs(int node,vector<int>&color,int col,vector<vector<int>>& adj){
        color[node]=col;
        for(auto it:adj[node]){
            if(color[it]==-1){
                if(dfs(it,color,!col,adj)==false)return false;
            }
            else if(color[it]==col)return false;

        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,color,0,adj)==false)return false;
            }
        }
        return true;
        
    }
};
