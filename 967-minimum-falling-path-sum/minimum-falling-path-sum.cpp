class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        
        // Define the recursive function with memoization
        function<int(int, int)> rec = [&](int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= n) return INT_MAX; // Out of bounds
            if (x == 0) return matrix[x][y]; // Base case: top row
            if (dp[x][y] != INT_MAX) return dp[x][y]; // Return memoized value if available
            
            // Calculate the minimum falling path sum recursively
            int left = rec(x - 1, y - 1);
            int middle = rec(x - 1, y);
            int right = rec(x - 1, y + 1);
            
            // Update the current cell's value in the DP table
            return dp[x][y] = matrix[x][y] + min({left, middle, right});
        };

        // Start the recursion from each cell in the first row
        int minPathSum = INT_MAX;
        for (int j = 0; j < n; ++j) {
            minPathSum = min(minPathSum, rec(n - 1, j));
        }

        return minPathSum;
    }
};