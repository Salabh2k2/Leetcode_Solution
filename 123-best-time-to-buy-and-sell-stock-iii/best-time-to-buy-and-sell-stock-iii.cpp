class Solution {
public:
    // day ==1 --> stock can be bought;
    int rec(int level, int day, int trans, int n, vector<int>& prices,vector<vector<vector<int>>>&dp)
    {   
        if(trans>=2) return 0;
        if(level==n) return 0;

        if(dp[level][day][trans]!=-1) return dp[level][day][trans];
        int profit = 0;
        if(trans<2 && day)
        {
            profit = max(-prices[level]+rec(level+1,0,trans,n,prices,dp), rec(level+1,1,trans,n,prices,dp)); 
        }
        else if(trans<2 && !day)
        {
            profit = max(prices[level]+rec(level+1,1,trans+1,n,prices,dp),rec(level+1,0,trans,n,prices,dp));
        }
        return dp[level][day][trans] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return rec(0,1,0,n,prices,dp);
    }
};