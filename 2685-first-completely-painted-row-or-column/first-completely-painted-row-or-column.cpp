class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int>row(n,0);
        vector<int>col(m,0);
        map<int, pair<int,int>>mp;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                mp[mat[i][j]] = {i,j};
            }
        }
        for(int i = 0;i<m*n;i++)
        {
            auto p = mp[arr[i]];
            row[p.first]++;
            col[p.second]++;
            if(row[p.first]==m|| col[p.second]==n)
            {
                return i;
            }
        }
        return -1;
    }
};