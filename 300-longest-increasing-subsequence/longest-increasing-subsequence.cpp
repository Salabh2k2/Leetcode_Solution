class Solution {
public:
    int rec(int level, int n, int last_taken, vector<int>& nums, vector<vector<int>>& dp) {
        if (level == n) return 0;
        // int taking in longest subseq.
        int len1 = 0;
        int len2 = 0;

        if (dp[level][last_taken + 1] != -1) return dp[level][last_taken + 1];
        if (last_taken == -1 || nums[level] > nums[last_taken]) {
            len1 = 1 + rec(level + 1, n, level, nums, dp);
        }
        len2 = rec(level + 1, n, last_taken, nums, dp);

        return dp[level][last_taken + 1] = max(len1, len2);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return rec(0, n, -1, nums, dp);
    }
};
