
class Solution {
public:
    bool isvalid(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    void dfs(int i, int j, vector<vector<int>>& grid, int n, int m) {
        if (!isvalid(i, j, n, m) || grid[i][j] == 0) {
            return;
        }

        grid[i][j] = 0;  // Mark as visited

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            dfs(x, y, grid, n, m);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Mark boundary connected 1s as visited
        for (int i = 0; i < n; i++) {
            dfs(i, 0, grid, n, m);
            dfs(i, m - 1, grid, n, m);
        }
        for (int i = 0; i < m; i++) {
            dfs(0, i, grid, n, m);
            dfs(n - 1, i, grid, n, m);
        }

        // Count remaining unvisited 1s
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
