class Solution {
public:
    int dfs(int i,int j,int R,int C,vector<vector<int>>& grid,vector<vector<int>>& visited){
        //out of bounds
        if(i<0 || j<0 || i>=R || j>=C) return 1;

        //water
        if(grid[i][j] == 0) return 1;

        //visited
        if(visited[i][j] == 1) return 0;

        visited[i][j] = 1;
        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};
        int perimeter = 0;
        for(int k=0;k<4;k++){
            perimeter += dfs(i+dr[k],j+dc[k],R,C,grid,visited);
        }
        return perimeter;

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();

        vector<vector<int>> visited(R,vector<int>(C,0));
        int perimeter = 0;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                     perimeter = dfs(i,j,R,C,grid,visited);
                }
            }
        }
        return perimeter;
    }
};