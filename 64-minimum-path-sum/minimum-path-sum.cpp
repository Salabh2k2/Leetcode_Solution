class Solution {
public:
    int rec(int x, int y, int m, int n, vector<vector<int>>& dp, vector<vector<int>>& grid) {
        if (!(x >= 0 && y >= 0 && x < m && y < n)) return INT_MAX;
        if (x == 0 && y == 0) return grid[x][y];
        if (dp[x][y] != INT_MAX) return dp[x][y];
        int ans1 = INT_MAX;
        int ans2 = INT_MAX;
        if (y - 1 >= 0)
            ans1 = grid[x][y] + rec(x, y - 1, m, n, dp, grid);
        if (x - 1 >= 0)
            ans2 = grid[x][y] + rec(x - 1, y, m, n, dp, grid); // Corrected passing y instead of m
        return dp[x][y] = min(ans1, ans2);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        return rec(m - 1, n - 1, m, n, dp, grid); // Corrected passing m and n as they are
    }
};
