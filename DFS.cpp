class Solution {
  public:
    void DFS(vector<int>&ans,int st,vector<vector<int>>& adj,vector<bool>&vis){
        ans.push_back(st);
        vis[st]=true;
        for(auto it:adj[st]){
            if(!vis[it]){
                DFS(ans,it,adj,vis);
            }
        }
        
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int v=adj.size();
        vector<bool>vis(v,false);
        vector<int>ans;
        int st=0;
        DFS(ans,st,adj,vis);
        return ans;
    }
};
