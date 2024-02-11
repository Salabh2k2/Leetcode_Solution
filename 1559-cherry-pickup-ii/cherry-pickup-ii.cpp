class Solution {
public:
    int cherryPickup(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> mem(m, vector<vector<int>>(n, vector<int>(n, -1)));

        // Start the recursion from the top-left corner of the grid
        return cherryPick(grid, 0, 0, n - 1, mem);
    }

private:
    int cherryPick(std::vector<std::vector<int>>& grid, int x, int y1, int y2, std::vector<std::vector<std::vector<int>>>& mem) {
        if (x == grid.size())
            return 0;

        if (y1 < 0 || y1 == grid[0].size() || y2 < 0 || y2 == grid[0].size())
            return 0;

        // Check if the result for the current state is already computed and stored in mem
        if (mem[x][y1][y2] != -1)
            return mem[x][y1][y2];

        // Calculate the cherries collected in the current row for both robots
        int currRow = grid[x][y1] + (y1 == y2 ? 0 : grid[x][y2]);

        // Explore all possible moves for both robots in the next row
        for (int d1 = -1; d1 <= 1; ++d1)
            for (int d2 = -1; d2 <= 1; ++d2)
                mem[x][y1][y2] = max(mem[x][y1][y2], currRow + cherryPick(grid, x + 1, y1 + d1, y2 + d2, mem));

        return mem[x][y1][y2];
    }
};