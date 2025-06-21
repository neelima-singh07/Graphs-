class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(V);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            adj[u].push_back({v,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; //declare priority queue 
        vector<int>dist(V,INT_MAX);
        dist[src]=0;
        pq.push({0,src}); //push dist,src 
        while(!pq.empty()){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            for(auto adjNode:adj[node]){
                int n=adjNode.first;
                int wt=adjNode.second;
                if(wt+dis<dist[n]){
                    dist[n]=wt+dis;
                    pq.push({dist[n],n});
                }
            }
        }
        return dist;
    }
};
