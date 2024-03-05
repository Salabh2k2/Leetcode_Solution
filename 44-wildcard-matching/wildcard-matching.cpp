class Solution {
public:
    bool solve(int i, int j, string &p, string &s, vector<vector<int>> &dp) {
        if(i < 0 && j < 0) return true;             // both strings get exhausted
        if(i < 0 && j >= 0) return false;           // s1 gets exhausted but s2 is remaining
        if(j < 0 && i >= 0) {                       // s2 gets exhausted but s1 is remaining.. this will be true only when all the characters in s1 are only '*'   
            for(int ii = 0; ii <= i; ii++) if(p[ii] != '*') return false;
            return true;
        }
        // if(i >= 0 && j < 0) return (count(p.begin(), p.begin()+i+1, '*') == p.size());     

        if(dp[i][j] != -1) return dp[i][j];


        if(p[i] == s[j] || p[i] == '?') return dp[i][j] = solve(i-1, j-1, p, s, dp);      // matching
        
        if(p[i] == '*') {      
            bool notconsider = solve(i-1, j, p, s, dp);
            bool consider = solve(i, j-1, p, s, dp);
            
            return dp[i][j] = consider || notconsider;
        }

        return dp[i][j] = false;       // not matching
    }

    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(n-1, m-1, p, s, dp);
    }
};
