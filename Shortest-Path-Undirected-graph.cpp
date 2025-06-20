class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int V=adj.size();
        queue<pair<int,int>>q;
        vector<int>vis(V);
        q.push({src,0});
        vis[src]=1;
        vector<int>dist(V,INT_MAX);
        while(!q.empty()){
            int node=q.front().first;
            int d=q.front().second;
            dist[node]=d;
            q.pop();
            for(auto it:adj[node]){
                if(vis[it]!=1){
                    vis[it]=1;
                    q.push({it,d+1});
                }
                
                
            }
            
            
            
        }
        for(int i=0;i<dist.size();i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        return dist;
        
        
    }
};
