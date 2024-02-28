class Solution {
public:
  int rec(int level, int sum, vector<int>& coins, vector<vector<int>>&dp) {
        if (sum < 0 || level < 0) return 0; 
        if (sum == 0) return 1;
        if(dp[level][sum]!=-1) return dp[level][sum];
        int includeCurrent = rec(level, sum - coins[level], coins,dp);
        int excludeCurrent = rec(level - 1, sum, coins,dp);
        return dp[level][sum] = includeCurrent + excludeCurrent;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int result = rec(n - 1, amount, coins, dp);
        
        return result == INT_MAX - 1 ? 0: result; 
    }
    int change(int amount, vector<int>& coins) {
        return coinChange(coins,amount);
    }
};