class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int ans = 0;
        int currentCost = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            currentCost += abs(s[i] - t[i]);

            // Adjust the window until the cost is within maxCost
            while (currentCost > maxCost) {
                currentCost -= abs(s[j] - t[j]);
                j++;
            }

            ans = max(ans, i - j + 1);
        }

        return ans;
    }
};
