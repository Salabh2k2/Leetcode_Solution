#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
int mod = 1e9 + 7;
class Solution {
public:
    Solution(){
        DPSolver; 
    }
    bool isOutside(int i, int j, int m, int n)
    {
        return i < 0 || j < 0 || i >= m || j >= n;
    }

    map<pair<pair<int,int>, int>, int> memo; 
    int findPaths(const int m,const int n, int maxMove, int startRow, int startColumn)
    {
        //?  make it efficient 
        auto it = memo.find({{startRow, startColumn},maxMove}); 
        if (it!= memo.end())
            return it->second; 
        //? make it work
        // base cases
        if (isOutside(startRow, startColumn, m, n)){
            memo[{{startRow, startColumn}, maxMove}] = 1;
            return 1;}
        
        else if (maxMove == 0)
            return 0; 


        // recursive case
        int up = findPaths(m, n, maxMove - 1, startRow - 1, startColumn) % mod;
        int down = findPaths(m, n, maxMove - 1, startRow + 1, startColumn) % mod;
        int left = findPaths(m, n, maxMove - 1, startRow , startColumn -1) % mod;
        int right = findPaths(m, n, maxMove - 1, startRow , startColumn+1) % mod;

        memo[{{startRow, startColumn}, maxMove}] = (((((up + down)%mod) + left)%mod) + right) %mod; 
        return (((((up + down)%mod) + left)%mod) + right) %mod; 
    }
};