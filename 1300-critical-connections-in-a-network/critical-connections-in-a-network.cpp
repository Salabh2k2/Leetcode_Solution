class Solution {
public:
    int timer = 1;
    void dfs(int node, int parent, vector<int>adj[], vector<int>&vis, int tin[], int low[], vector<vector<int>> &bridges)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto it:adj[node])
        {
            if(it==parent) continue;
            if(vis[it])
            {
                low[node] = min(low[node],low[it]);
            }
            else{
                dfs(it,node,adj,vis,tin,low,bridges);
                low[node] = min(low[it],low[node]);
                if(low[it]>tin[node])
                {
                    bridges.push_back({node,it});
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        vector<int>adj[n];
        for(auto it:connections)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        vector<vector<int>>bridges;
        int tin[n];
        int low[n];
        dfs(0,-1,adj,vis,tin,low,bridges);
        return bridges;

    }
};