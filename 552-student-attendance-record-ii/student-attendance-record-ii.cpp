class Solution {
public:
    const int mod = 1e9+7;
    long long rec(int level, int ab, int late, int n, vector<vector<vector<long long>>>& dp)
    {
        // Base case: if the current level is equal to n, return 1
        if (level == n) {
            return 1LL;
        }

        // If this state has already been computed, return its value
        if (dp[level][ab][late] != -1) return dp[level][ab][late];

        // Initialize possible results
        long long ans1 = 0, ans2 = 0, ans3 = 0;

        // Consider adding an 'A' (absent) if we haven't added one yet
        if (ab < 1) {
            ans1 = rec(level + 1, ab + 1, 0, n, dp);
        }

        // Consider adding an 'L' (late) if the current streak of lates is less than 2
        if (late < 2) {
            ans2 = rec(level + 1, ab, late + 1, n, dp);
        }

        // Consider adding a 'P' (present)
        ans3 = rec(level + 1, ab, 0, n, dp);

        // Store the result in dp array and return it
        return dp[level][ab][late] = (ans1 + ans2 + ans3)%mod;
    }

    int checkRecord(int n) {
        // Initialize dp array with -1
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(2, vector<long long>(3, -1)));
        
        // Calculate the result and cast to int for the final return
        return static_cast<int>(rec(0, 0, 0, n, dp));
    }
};
