class DSU
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
        }
    }

    int findpar(int u)
    {
        if (u == parent[u])
            return u;
        return parent[u] = findpar(parent[u]);
    }

    void unioubyrank(int a, int b)
    {
        int pa = findpar(a);
        int pb = findpar(b);
        if (pa == pb)
            return;
        if (rank[pa] > rank[pb])
        {
            parent[pb] = pa;
        }
        else if (rank[pa] < rank[pb])
        {
            parent[pa] = pb;
        }
        else
        {
            parent[pb] = pa;
            rank[pa]++;
        }
    }
};

class Solution {
public:
    void dfs(int i, vector<int>adj[],vector<int>&vis)
    {
        vis[i] = 1;
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        vector<int>vis(n,0);
        for(auto it: connections)
        {
            int a = it[0];
            int b = it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int connected = 0;
        for(int i = 0;i<n;i++)
        {
            if(!vis[i])
            {
                connected++;
                dfs(i,adj,vis);
            }
        }
        DSU ds(n);
        int extra = 0;
        for(auto it: connections)
        {
            int a = it[0];
            int b = it[1];
            if(ds.findpar(a)==ds.findpar(b))
            {
                extra++;
                continue;
            }
            ds.unioubyrank(a,b);
        }
       if(extra>=connected-1) return connected-1;
       else return -1;
    }
};