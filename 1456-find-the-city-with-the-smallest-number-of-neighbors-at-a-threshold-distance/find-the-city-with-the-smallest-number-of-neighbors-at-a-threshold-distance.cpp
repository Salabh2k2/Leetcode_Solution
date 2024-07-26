class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> cost(n, vector<int>(n, 1e9));
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            cost[u][v] = wt;
            cost[v][u] = wt; 
        }
        
        for(int i = 0; i < n; i++) {
            cost[i][i] = 0;
        }
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
        
        map<int,int> reachableCities;
        for(int i = 0; i < n; i++) {
            int reachableCount = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && cost[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }
            reachableCities[i] = reachableCount;
        }
        
        int minReachableCount = n, minCity = -1;
        for(auto it : reachableCities) {
            if(it.second <= minReachableCount) {
                minReachableCount = it.second;
                minCity = it.first;
            }
        }
        
        return minCity;
    }
};