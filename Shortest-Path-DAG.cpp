// User function Template for C++
class Solution {
  public:
    void dfs(int node,vector<vector<pair<int,int>>>&adj,vector<int>&vis,stack<int>&st){
        vis[node]=1;
        for(auto it : adj[node]){
            if(vis[it.first]!=1){
                dfs(it.first,adj,vis,st);
            }
        }
        st.push(node);
        
      
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            adj[u].push_back({v,wt});
            
        }
        vector<int>vis(V,0);
        
        stack<int>st;
        //first find toplogical sort 
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,adj,vis,st);
            }
        }
        vector<int>dist(V,INT_MAX);
        //then ealx the edges 
        dist[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if (dist[node] != INT_MAX) { // Only process if reachable
                for (auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
    
};
