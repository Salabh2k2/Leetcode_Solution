
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> count(n, 1); // Number of nodes in subtree rooted at i
        vector<int> result(n, 0); // Sum of distances for each node
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1, adj, count, result);
        dfs2(0, -1, adj, count, result, n);

        return result;
    }

private:
    void dfs(int node, int parent, const vector<vector<int>>& adj, vector<int>& count, vector<int>& result) {
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, adj, count, result);
                count[node] += count[neighbor];
                result[node] += result[neighbor] + count[neighbor];
            }
        }
    }

    void dfs2(int node, int parent, const vector<vector<int>>& adj, const vector<int>& count, vector<int>& result, int n) {
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                result[neighbor] = result[node] - count[neighbor] + n - count[neighbor];
                dfs2(neighbor, node, adj, count, result, n);
            }
        }
    }
};