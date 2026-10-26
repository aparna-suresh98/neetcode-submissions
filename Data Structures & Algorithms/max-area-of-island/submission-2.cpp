class Solution {
public:
    int bfs(int i,int j,vector<vector<int>>& grid, vector<vector<int>>& visited,int n,int m){
        visited[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i,j});
        int Area =1;

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int dr[] = {1,-1,0,0};
            int dc[] = {0,0,1,-1};

            for(int k=0;k<4;k++){
                int nrow = row + dr[k];
                int ncol = col + dc[k];

                if(nrow >= 0 && ncol >= 0 && nrow< n && ncol < m && grid[nrow][ncol] != 0 && visited[nrow][ncol] == 0){
                    visited[nrow][ncol] = 1;
                    Area++;
                    q.push({nrow,ncol});
                }
            }
        }
        return Area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxArea = 0;
        vector<vector<int>> visited(n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    int Area  = bfs(i,j,grid,visited,n,m);
                    maxArea = max(maxArea,Area);
                }
            }
        }
        return maxArea;

    }
};
