class Solution {
public:
    bool isvalid(int x, int y, int n, int m)
    {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }

    bool dfs(int i, int j, int n, int m, vector<vector<char>> &board, vector<vector<int>> &vis, string word, int left, int k)
    {
        vis[i][j] = 1;
        if (left == k - 1)
        {
            return true;
        }
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        for (int d = 0; d < 4; d++)
        {
            int x = i + dx[d];
            int y = j + dy[d];
            if (isvalid(x, y, n, m) && !vis[x][y] && word[left + 1] == board[x][y])
            {
                if (dfs(x, y, n, m, board, vis, word, left + 1, k))
                    return true;
            }
        }
        vis[i][j] = 0; // Backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int k = word.size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(i, j, n, m, board, vis, word, 0, k))
                        return true;
                }
            }
        }
        return false;
    }
};
