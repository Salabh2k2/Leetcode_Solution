class Solution {
public:
    int dp[1000];
    int rec(int level, int n)
    {
        if(level==1) return 1;
        if(level==2) return 2;
        dp[0] = 1; dp[1] = 2;
        int ans = 0;
        if(dp[level]!=-1){
            return dp[level];
        }
        ans+=rec(level-1,n)+rec(level-2,n);
        return dp[level] = ans;;
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
       return rec(n,n);

    }
};