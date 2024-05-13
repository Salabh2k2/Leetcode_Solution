
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 0) {
                for(int j = 0; j < m; j++) {
                    grid[i][j] = !grid[i][j];
                }
            }
        }
        
       
        for(int j = 1; j < m; j++) {
            int ct_0 = 0;
            int ct_1 = 0;
            for(int i = 0; i < n; i++) {
                if(grid[i][j] == 0) ct_0++;
                else ct_1++;
            }
            if(ct_1 < ct_0) {
                for(int i = 0; i < n; i++) {
                    grid[i][j] = !grid[i][j];
                }
            }
        }
        

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int temp = 0;
            for(int j = 0; j < m; j++) {
                temp *= 2;
                temp += grid[i][j];
            }
            ans += temp;
        }
        
        return ans;
    }
};

