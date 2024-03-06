class Solution {
public:

    int rec(int level, int buy, int n,  vector<int>&prices, vector<vector<int>>&dp)
    {
        if(level==n) return 0;
        
        if(dp[level][buy]!=-1) return dp[level][buy];
        int profit = 0;
        if(buy)
        {
            profit = max(-prices[level]+rec(level+1,0,n,prices,dp), rec(level+1,1,n,prices,dp));
        }
        else profit = max(prices[level]+rec(level+1,1,n,prices,dp), rec(level+1,0,n,prices,dp));
        return dp[level][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return rec(0,1,n,prices,dp);
    }
};