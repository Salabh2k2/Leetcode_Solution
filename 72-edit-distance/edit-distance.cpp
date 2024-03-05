class Solution {
public:
    int rec(int x, int y, string &word1, string &word2, vector<vector<int>>& dp) {
        // Base case: if one of the strings is empty, return the length of the other string
        if (x < 0) return y + 1;
        if (y < 0) return x + 1;

        // If the result is already computed, return it
        if (dp[x][y] != -1) return dp[x][y];

        // If characters match, continue to the next characters
        if (word1[x] == word2[y]) {
            return dp[x][y] = rec(x - 1, y - 1, word1, word2, dp);
        } else {
            // If characters don't match, try three possible operations: delete, insert, or replace
            return dp[x][y] = 1 + min({rec(x - 1, y, word1, word2, dp), rec(x, y - 1, word1, word2, dp), rec(x - 1, y - 1, word1, word2, dp)});
        }
    }

    int minDistance(string word1, string word2) {
        // Initialize the dp table with -1
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        // Call the recursive function starting from the end of both strings
        return rec(word1.size() - 1, word2.size() - 1, word1, word2, dp);
    }
};