class Solution {
public:
    bool toposort(int v, vector<bool>& vis, vector<bool>& recStack, vector<int>& ans, vector<int> adj[]) {
        vis[v] = true;
        recStack[v] = true;

        for (auto it : adj[v]) {
            if (!vis[it] && toposort(it, vis, recStack, ans, adj)) {
                return true;
            } else if (recStack[it]) {
                return true;
            }
        }

        recStack[v] = false;
        ans.push_back(v);
        return false;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> adj1[k + 1];
        vector<int> adj2[k + 1];

        for (auto it : rowConditions) {
            adj1[it[0]].push_back(it[1]);
        }
        for (auto it : colConditions) {
            adj2[it[0]].push_back(it[1]);
        }

        vector<int> row;
        vector<int> col;
        vector<bool> vis1(k + 1, false);
        vector<bool> recStack1(k + 1, false);
        vector<bool> vis2(k + 1, false);
        vector<bool> recStack2(k + 1, false);

        for (int i = 1; i <= k; i++) {
            if (!vis1[i] && toposort(i, vis1, recStack1, row, adj1)) {
                return {};
            }
            if (!vis2[i] && toposort(i, vis2, recStack2, col, adj2)) {
                return {};
            }
        }

        reverse(row.begin(), row.end());
        reverse(col.begin(), col.end());

        if (row.size() != k || col.size() != k) {
            return {};
        }

        map<int, int> mp1;
        map<int, int> mp2;

        for (int i = 0; i < row.size(); i++) {
            mp1[row[i]] = i;
        }
        for (int i = 0; i < col.size(); i++) {
            mp2[col[i]] = i;
        }

        vector<vector<int>> ans(k, vector<int>(k, 0));
        for (int i = 1; i <= k; i++) {
            ans[mp1[i]][mp2[i]] = i;
        }

        return ans;
    }
};
