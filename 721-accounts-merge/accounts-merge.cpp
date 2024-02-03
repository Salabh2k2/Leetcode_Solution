class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }
    }

    int findpar(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = findpar(parent[u]);
    }

    void unionbyrank(int a, int b) {
        int pa = findpar(a);
        int pb = findpar(b);
        if (pa == pb)
            return;
        if (rank[pa] > rank[pb]) {
            parent[pb] = pa;
        } else if (rank[pa] < rank[pb]) {
            parent[pa] = pb;
        } else {
            parent[pb] = pa;
            rank[pa]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        map<string, int> mp;
        DSU ds(n);
        for (int i = 0; i < n; i++) {
            int k = i;
            // bool flag = false;
            for (int j = 1; j < accounts[i].size(); j++) { // Corrected loop
                if (mp.find(accounts[i][j]) == mp.end()) {
                    mp[accounts[i][j]] = i;
                } else {
                    ds.unionbyrank(i, mp[accounts[i][j]]);
                }
            }
        }
        vector<string> adj[n];
        for (auto it : mp) {
            string mail = it.first;
            int node = ds.findpar(it.second); // Corrected indexing
            adj[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 0)
                continue;
            sort(adj[i].begin(), adj[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : adj[i]) { // Iterate over adj[i], not accounts[i]
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
