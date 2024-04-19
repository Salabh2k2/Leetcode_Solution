class Solution {
public:

    void dfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>&grid)
    {
        vis[row][col] = 1;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        for(int i = 0;i<4;i++)
        {
            int newr = row+dx[i];
            int newc = col+dy[i];
            if(newr>=0 && newr<grid.size() && newc>=0 && newc<grid[0].size() && vis[newr][newc]==0 && grid[newr][newc]=='1')
            {
                dfs(newr, newc,vis,grid);
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int cc = 0;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==0)
                {
                    dfs(i,j,vis,grid);
                    cc++;
                }
            }
        }
        return cc;
    }
};