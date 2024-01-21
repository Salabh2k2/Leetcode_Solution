class Solution {
public:
    int dp[100001];
    vector<int>chosen;
    int rec(int level, int n, vector<int>nums)
    {
        if(level<0) return 0;
        
        int ans = 0;
        //if i choose
        if(dp[level]!=-1) return dp[level];
        ans = max(ans,rec(level-2,n,nums)+nums[level]);
        // if i donot choose
         ans = max(ans,rec(level-1,n,nums));
        return dp[level] = ans;
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return rec(n-1,n,nums);
        
    }
};