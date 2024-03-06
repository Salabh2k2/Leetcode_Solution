class Solution {
public:
    int rec(int level, int day, int n, vector<int>prices, vector<vector<int>>&dp)
    {

        if(level>=n) return 0;
        int profit = 0;

        if(dp[level][day]!=-1) return dp[level][day];
        if(day)
        {
            profit = max(-prices[level]+rec(level+1, 0,n,prices,dp), rec(level+1,1,n,prices,dp));
        }
        else{
            profit = max(prices[level] + rec(level+2,1,n,prices,dp), rec(level+1,0,n,prices,dp));
        }

        return dp[level][day] = profit;

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return rec(0,1,n,prices,dp);
    }
};