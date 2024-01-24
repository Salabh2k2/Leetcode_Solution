class Solution {
public:
    bool isvalid(int x,int y, int n, int m)
    {
        if(x>=0 && x<n && y>=0 && y<m)
        {
            return true;
        }
        return false;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        int n = image.size();
        int m = image[0].size();
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        int c = image[sr][sc];
        vector<vector<int>>vis(n,vector<int>(m,0));
        q.push({sr,sc});
        while(!q.empty())
        {
            pair<int,int>p = q.front();
            int x = p.first; int y = p.second;
            vis[x][y] = 1;
            q.pop();
            image[x][y] = color;
            for(int k = 0;k<4;k++){
                int  i = x+dx[k];
                int j = y+dy[k];
                if(isvalid(i,j,n,m) && image[i][j]==c && vis[i][j]!=1) q.push({i,j});
            }
        }
        return image;

    }
};