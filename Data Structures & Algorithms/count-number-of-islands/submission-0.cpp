class Solution {
public:

    void dfs(int r, int c, vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    // out of bounds or water: stop
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0')
        return;

    grid[r][c] = '0';          // mark visited (sink the land)

    dfs(r + 1, c, grid);       // down
    dfs(r - 1, c, grid);       // up
    dfs(r, c + 1, grid);       // right
    dfs(r, c - 1, grid);       // left
}

    int numIslands(vector<vector<char>>& grid) {
    int rows = grid.size();
    if (rows == 0) return 0;
    int cols = grid[0].size();
    int count = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '1') {
                count++;               // new island found
                dfs(i, j, grid);       // sink the whole island
            }
        }
    }
    return count;
    }
};
