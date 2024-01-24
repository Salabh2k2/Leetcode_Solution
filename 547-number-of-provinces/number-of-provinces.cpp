class Solution {
public:
    void dfs(int node,vector<int>adj[],vector<int>&vis)
    {
        vis[node] = 1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();
        vector<int>adj[n];
        vector<int>vis(n,0);
        for(int i = 0; i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i = 0;i<n;i++)
        {
            if(!vis[i]){
            ans++;
            dfs(i,adj,vis);
            }
        }
        return ans;
    }
};