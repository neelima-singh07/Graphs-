class Solution {
  public:
    void dfs(int node,vector<bool>&vis,vector<vector<int>>&adj,vector<int>&topo,stack<int>&st){
        
        vis[node]=true;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,topo,st);
                
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>topo;
        vector<vector<int>>adj(V);
        //convert list of edges to adjl
        for(auto edge:edges){
            int u=edge[0];int v=edge[1];
            adj[u].push_back(v);
        }
        vector<bool>vis(V);
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,topo,st);
            }
        }
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
        
        
    }
};
