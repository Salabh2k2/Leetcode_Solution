class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();      
        if(grid[0][0]!=0) return -1; 
        if(n==1) return 1;    
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 1;
        q.push({1, {0, 0}});
        int delr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int delc[] = {0, 1, 1, 1, 0, -1, -1, -1};

        while (!q.empty()) {
            auto it = q.front();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            q.pop();

            for (int i = 0; i < 8; i++) {
                int nrow = r + delr[i];
                int ncol = c + delc[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol]) {
                    dist[nrow][ncol] = dis + 1;
                    if (nrow == n - 1 && ncol == n - 1)
                        return dist[nrow][ncol];
                    q.push({dis + 1, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};