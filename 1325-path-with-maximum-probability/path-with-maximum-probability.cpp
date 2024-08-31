#include <vector>
#include <queue>
#include <utility>

class Solution {
public:
    double maxProbability(int n, std::vector<std::vector<int>>& edges, std::vector<double>& succProb, int start_node, int end_node) {
        // Create the adjacency list
        std::vector<std::vector<std::pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        // Initialize distance vector with 0 and set the start_node probability to 1
        std::vector<double> dist(n, 0.0);
        dist[start_node] = 1.0;

        // Max-heap priority queue to store the maximum probability path
        std::priority_queue<std::pair<double, int>> pq;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();

            if (node == end_node) {
                return prob;  // If we reached the end_node, return the probability
            }

            for (auto& [adj_node, edge_prob] : adj[node]) {
                double new_prob = prob * edge_prob;
                if (new_prob > dist[adj_node]) {
                    dist[adj_node] = new_prob;
                    pq.push({new_prob, adj_node});
                }
            }
        }

        // If we can't reach the end_node, return 0
        return 0.0;
    }
};
