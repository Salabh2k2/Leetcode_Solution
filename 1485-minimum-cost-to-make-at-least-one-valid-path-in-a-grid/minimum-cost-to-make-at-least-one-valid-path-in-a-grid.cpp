class Solution {
public:
    struct Compare {
        bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<0>(a) > get<0>(b); // Min-heap: smallest cost at the top
        }
    };
    
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Priority queue to store {cost, i, j}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Compare> pq;
        vector<vector<int>> visited(n, vector<int>(m, INT_MAX)); // Visited with min cost
        
        pq.push({0, 0, 0}); // Start at top-left with cost 0
        visited[0][0] = 0;
        
        // Direction vectors for 1: right, 2: left, 3: down, 4: up
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!pq.empty()) {
            auto [cost, i, j] = pq.top();
            pq.pop();
            
            // If we reach the bottom-right corner
            if (i == n - 1 && j == m - 1) return cost;
            
            // Skip if we've already visited this cell with a smaller cost
            if (cost > visited[i][j]) continue;
            
            // Current direction from the grid
            int dir = grid[i][j];
            
            // Move in the intended direction without additional cost
            int ni = i + directions[dir - 1].first;
            int nj = j + directions[dir - 1].second;
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && cost < visited[ni][nj]) {
                visited[ni][nj] = cost;
                pq.push({cost, ni, nj});
            }
            
            // Try all other directions with +1 cost
            for (int k = 0; k < 4; ++k) {
                if (k == dir - 1) continue; // Skip the intended direction
                ni = i + directions[k].first;
                nj = j + directions[k].second;
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && cost + 1 < visited[ni][nj]) {
                    visited[ni][nj] = cost + 1;
                    pq.push({cost + 1, ni, nj});
                }
            }
        }
        
        return -1; // Should not reach here for valid input
    }
};
