class Solution {
public:
    long long dp[501][501][3] ;
    bool visited[501][501][3] ;
    long long helper(int i , int j , int count , vector<vector<int>> &coins) {
        int n = coins.size() , m = coins[0].size() ;
        if( i == coins.size()-1 && j == coins[0].size()-1 ) {
            if( coins[i][j] < 0 && count > 0 ) return 0 ;
            return coins[i][j] ;
        }
        if( i >= coins.size() || j >= coins[0].size() ) return INT_MIN ;

        if( visited[i][j][count] ) return dp[i][j][count] ;
        
        long long right = INT_MIN , down = INT_MIN;

        
        right = coins[i][j] + helper(i , j+1 , count , coins) ;
        if( count > 0 && coins[i][j] < 0 ) {
            right = max(right , helper(i , j +1 , count-1 , coins)) ;
        }
        

        
        down = helper(i+1 , j , count , coins) + coins[i][j] ;
        if( count > 0 && coins[i][j] < 0 ) 
            down = max(down , helper(i+1 , j , count -1 , coins)) ;
        

        visited[i][j][count] = 1 ;
        return dp[i][j][count] = max(right , down) ;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        memset(dp , -1 , sizeof(dp)) ;
        memset(visited , 0 , sizeof(visited)) ;
        return helper(0 , 0 , 2 , coins) ;
    }
};