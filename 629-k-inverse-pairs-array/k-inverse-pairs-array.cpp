#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int dp[1001][1001];
    int mod=1e9+7;
    long long f(int n, int k){
        if (k==0) return 1;
        if (k<0 || n<=0) return 0;
        if(dp[n][k]!=-1) return dp[n][k];
        return dp[n][k]=(f(n-1, k)+f(n, k-1)-f(n-1, k-n)+mod)%mod;
    }
    int kInversePairs(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return f(n, k);
    }
};