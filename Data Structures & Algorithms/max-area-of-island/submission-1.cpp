class Solution {
public:
int bfs(int i,int j,int n, int m,vector<vector<int>>& grid,vector<vector<int>>& visited){

    queue<pair<int,int>> q;
    visited[i][j] = 1;
    q.push({i,j});
    int area = 1;
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};

        for(int k =0;k<4;k++){
            int nrow = row + dr[k];
            int ncol = col + dc[k];

            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1 && visited[nrow][ncol] == 0){
                area++;
                visited[nrow][ncol] = 1;
                q.push({nrow,ncol});
            }
        }
    }
    return area;
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n,vector<int> (m,0));
    int maxarea =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1 && visited[i][j] == 0){
                maxarea = max(maxarea, bfs(i,j,n,m,grid,visited));
            }
        }
    }
    return maxarea;
    }
};
