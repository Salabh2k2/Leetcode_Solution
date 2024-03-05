class Solution {
public:
   int rec(int x, int y, string &s1, string &s2, vector<vector<int>>&dp)
    {
        if(y<0) return 1;
        if(x<0) return 0;

        if(dp[x][y]!=-1) return dp[x][y];
        if(s1[x]==s2[y])
        {
            return dp[x][y] = rec(x-1,y-1,s1,s2,dp) + rec(x-1,y,s1,s2,dp);
        }
        else{
            return dp[x][y] = rec(x-1,y,s1,s2,dp);
        }
    }
    int numDistinct(string s, string t) {
         int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return rec(n-1,m-1,s,t,dp);
    }
};