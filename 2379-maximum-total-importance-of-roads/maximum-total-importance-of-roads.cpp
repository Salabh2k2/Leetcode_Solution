class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> adj[n];
        for (const auto& road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }

        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = adj[i].size();
        }
        sort(v.begin(), v.end());

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (long long)(i + 1) * v[i];
        }
        return ans;
    }
};
