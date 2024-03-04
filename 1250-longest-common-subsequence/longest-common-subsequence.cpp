class Solution {
public:
    int rec(int level1, int level2, string &text1, string &text2, vector<vector<int>>&dp)
    {
        if(level1<0 || level2<0) return 0 ;

        if(dp[level1][level2]!=-1) return dp[level1][level2];

        if(text1[level1]==text2[level2])
        {
            return dp[level1][level2] = 1+ rec(level1-1, level2-1, text1, text2, dp);
        }

        return dp[level1][level2] = max(rec(level1-1,level2,text1,text2,dp), rec(level1,level2-1,text1,text2,dp));

    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return (rec(n-1,m-1,text1,text2,dp));
    }
};