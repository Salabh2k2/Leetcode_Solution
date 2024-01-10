class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& dis) {
        vis[node] = 1;
        for (auto child : adj[node]) {
            if (!vis[child]) {
                dis[child] = dis[node] + 1;
                dfs(child, adj, vis, dis);
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        if (!root) {
            return 0; 
        }

        vector<vector<int>> adj(1e5 + 1);  
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* k = q.front();
            int a = k->val;
            q.pop();

            if (k->left) {
                q.push(k->left);
                int b = k->left->val;
                adj[a].push_back(b);
                adj[b].push_back(a);
            }

            if (k->right) {
                q.push(k->right);
                int c = k->right->val;
                adj[a].push_back(c);
                adj[c].push_back(a);
            }
        }

        vector<int> vis(adj.size(), 0);
        vector<int> dist(adj.size(), 0);
        dist[start] = 0;
        dfs(start, adj, vis, dist);

        int mx = -1;
        for (int i = 0; i < dist.size(); i++) {
            mx = max(mx, dist[i]);
        }

        return mx;
    }
};
