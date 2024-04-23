#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0}; 
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0); 
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1)
                leaves.push(i);
        }
    
        while (n > 2) {
            int numLeaves = leaves.size();
            n -= numLeaves;
            for (int i = 0; i < numLeaves; ++i) {
                int leaf = leaves.front();
                leaves.pop();
                for (int neighbor : adj[leaf]) {
                    if (--degree[neighbor] == 1)
                        leaves.push(neighbor);
                }
            }
        }
        
        vector<int> centroids;
        while (!leaves.empty()) {
            centroids.push_back(leaves.front());
            leaves.pop();
        }
        
        return centroids;
    }
};
