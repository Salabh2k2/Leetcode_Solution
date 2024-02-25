class Solution {
public:
    bool rec(int level, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        if (sum == 0) {
            return true; // If one subset sum becomes zero, the other subset has to have the remaining sum
        }
        if (level == nums.size() || sum < 0) {
            return false; // If we reach the end of the array or the sum becomes negative, no valid partition found
        }
        if (dp[level][sum] != -1) {
            return dp[level][sum]; // If the result for this state is already computed, return it
        }

        // Recursively check if the current element can be included in the subset or not
        bool include = rec(level + 1, sum - nums[level], nums, dp);
        bool exclude = rec(level + 1, sum, nums, dp);

        // Update the dp table with the result and return it
        return dp[level][sum] = include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int num : nums) {
            total += num;
        }

        if (total % 2 != 0) {
            return false; // If the total sum is odd, it cannot be partitioned into two equal subsets
        }

        int target = total / 2; // Target sum for each subset
        int n = nums.size();

        // Initialize dp array with -1
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        // Start recursion from level 0 with sum equal to the target
        return rec(0, target, nums, dp);
    }
};