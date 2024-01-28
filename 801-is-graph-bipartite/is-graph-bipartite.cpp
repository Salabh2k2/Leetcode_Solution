class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<pair<int,int>> q;
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> col(n,-1);
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                q.push({i,0});
                
                while(!q.empty()) {
                    int k = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    
                    if(vis[k]) {
                        if(col[k] != c) return false;
                        continue;
                    }
                    
                    vis[k] = 1;
                    col[k] = c;
                    
                    for(auto it : graph[k]) {
                        if(!vis[it]) {
                            q.push({it, c^1});
                        }
                    }
                }
            }
        }
        return true;
    }
};
