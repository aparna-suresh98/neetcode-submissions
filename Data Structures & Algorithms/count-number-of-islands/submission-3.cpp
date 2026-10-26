class Solution {
public:
        void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& visited){
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        visited[i][j] = 1;
        q.push({i,j});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int dr[] = {1,-1,0,0};
            int dc[] = {0,0,1,-1};

            for(int k=0;k<4;k++){
                int nrow = row +dr[k];
                int ncol = col +dc[k];

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] != '0' && visited[nrow][ncol] != 1 ){
                    visited[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int count =0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    count++;
                    bfs(i,j,grid,visited);
                }
            }
        }
        return count;
    }
};
