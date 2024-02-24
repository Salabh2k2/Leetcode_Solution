class Solution {
public:
      bool isvalid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    
    int rec(int x, int y, int m, int n, vector<vector<int>>& dp,vector<vector<int>>obstacle) {
         if(obstacle[x][y]==1) return 0;
        if (x == 0 && y == 0) {
            return 1;
        }
      
        
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        
        int dx[2] = {-1, 0};
        int dy[2] = {0, -1};
        int paths = 0;
        
        for (int i = 0; i < 2; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (isvalid(newx, newy, m, n)) {
                paths += rec(newx, newy, m, n, dp,obstacle);
            }
        }
        
        return dp[x][y] = paths;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m,n;
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return rec(m-1,n-1,m,n,dp,obstacleGrid);
    }
};