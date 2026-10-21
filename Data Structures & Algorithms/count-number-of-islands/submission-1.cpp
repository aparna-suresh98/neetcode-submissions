class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>& visited,vector<vector<char>>& grid){
        visited[row][col] =1;
        queue<pair<int,int>> q;

        int n = grid.size();
        int m = grid[0].size();
        q.push({row,col});

        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            //traverse in neighbor
            for(int k=0;k<4;k++){
                    int nrow = row + dr[k];
                    int ncol = col + dc[k];
                    if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && grid[nrow][ncol] == '1' &&  visited[nrow][ncol] == 0){
                        visited[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size();
        int C = grid[0].size();

        vector<vector<int>> visited (R,vector<int>(C,0));
        
        int cnt =0;
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i,j,visited,grid);
                }
            }
        }
        return cnt;
    }
};
