class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,vector<bool>&vis,vector<int>&path_vis){
        vis[node]=true;
        path_vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,path_vis)==true)return true;
            }
            else if(path_vis[it]==1 && vis[it]==1)return true;
        }
        path_vis[node]=0;
        return false;

    }
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        for(auto edge : edges){
            int u=edge[0];
            int v=edge[1];
            adj[v].push_back(u); 
        }
        
        vector<bool>vis(V);
        vector<int>path_vis(V);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path_vis)==true)return false;
            }

        }
        return true;
        
    }
};
