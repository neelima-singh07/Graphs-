lass Solution {
  public:
    bool dfs(int node,vector<vector<int>> &adj,vector<int>&vis,vector<int>&path_vis){
        vis[node]=1;
        path_vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]!=1){
                if(dfs(it,adj,vis,path_vis)==true)return true;;
            }
            else if(vis[it]==1 && path_vis[it]==1)return true;
        }
        path_vis[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
        }
        vector<int>vis(V,0);
        vector<int>path_vis(V,0);
        
        for(int i=0;i<V;i++){
            if(vis[i]!=1){
                if(dfs(i,adj,vis,path_vis)==true)return true;
            }
        }
        return false;
    }
};
