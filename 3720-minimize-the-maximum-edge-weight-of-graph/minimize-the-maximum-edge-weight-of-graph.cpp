class Solution {
public:
    void dfs(int node, vector<pair<int, int>> adjR[], vector<int>& vis, int mid) {
        vis[node] = 1;
        for (auto it : adjR[node]) {
            int neighbor = it.first;
            int weight = it.second;
            if (weight <= mid && !vis[neighbor] ) {
                dfs(neighbor, adjR, vis, mid);
            }
        }
    }

    bool check(vector<pair<int, int>> adjR[], int mid, int n) {
        vector<int> vis(n + 1, 0);
        dfs(0, adjR, vis, mid);
        for (int i = 0; i <n; i++) {
            if (vis[i] == 0) return false;
        }
        return true;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<pair<int, int>> adjR[n + 1];
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            //adjR[u].push_back({v, wt});
            adjR[v].push_back({u, wt}); // Assuming an undirected graph.
        }

        int lo = 1, hi = 1000001, ans = -1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(adjR, mid, n)) {
                ans = mid;
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
