class Solution {
public:
int rob1(vector<int>& nums) {
        int n  = nums.size();
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        dp[0]= 0;
        dp[1] = nums[0];
        for(int i = 2;i<=n;i++)
        {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>first= {nums.begin(),nums.begin()+n-1};
        vector<int>second = {nums.begin()+1,nums.end()};
        return max(rob1(first), rob1(second));
    }
};