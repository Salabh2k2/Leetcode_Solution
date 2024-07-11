class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ans = 0;
        int n = colors.size();

        if (n < 3) return 0; // If the array is too small, there can be no valid groups

        // Loop to check the alternating groups
        for (int i = 0; i < n; ++i) {
            if (colors[i] != colors[(i + 1) % n] && colors[i] == colors[(i + 2) % n]) {
                ans++;
            }
        }
        return ans;
    }
};
