#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(int i = 0; i < times.size(); i++) {
            auto it = times[i];
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        vector<int> wt(n+1, INT_MAX);
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        wt[k] = 0;
        pq.push({0, k});
        
        while (!pq.empty()) {
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int timeTaken = it.second;
                if (time + timeTaken < wt[adjNode]) {
                    wt[adjNode] = time + timeTaken;
                    pq.push({wt[adjNode], adjNode}); 
                }
            }
        }
        
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, wt[i]);
        }
        
        return (ans != INT_MAX) ? ans : -1;
    }
};
