class Solution {
public:

    void bfs(int i,int j,int R,int C,vector<vector<char>>& grid,vector<vector<int>>& visited){
        queue<pair<int,int>> q;
        visited[i][j] = 1;
        q.push({i,j});
        int dr[]= {1,-1,0,0};
        int dc[]={0,0,1,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int k =0;k<4;k++){
                int nrow = row+dr[k];
                int ncol = col+dc[k];

                if(nrow >=0 && ncol>=0 && nrow<R && ncol<C && grid[nrow][ncol] == '1' && visited[nrow][ncol] == 0){
                    visited[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size();
        int C = grid[0].size();

        int count =0;
        vector<vector<int>> visited(R,vector<int> (C,0));

        for(int i =0;i<R;i++){
            for(int j=0;j<C;j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    count++;
                    bfs(i,j,R,C,grid,visited);
                }
            }
        }
        return count;
    }
};
