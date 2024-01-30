class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i = 0;i<flights.size();i++)
        {
            int from = flights[i][0];
            int to = flights[i][1];
            int dist = flights[i][2];
            adj[from].push_back({to,dist});
        }
        vector<int>dist(n,INT_MAX);
        dist[src] = 0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stop = it.first;
            int node = it.second.first;
            int dis = it.second.second;
            if(stop>k) continue;
            for(auto edge:adj[node])
            {
                int newn = edge.first;
                int wt = edge.second;
                if(wt+dis<dist[newn] && stop<=k)
                {
                    dist[newn] = wt+dis;
                    q.push({stop+1,{newn,dist[newn]}});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        else return dist[dst];
    }
};