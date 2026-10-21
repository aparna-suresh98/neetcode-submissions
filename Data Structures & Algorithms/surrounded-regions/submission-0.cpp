class Solution {
public:

    void bfs(int R,int C,queue<pair<int,int>>& q,vector<vector<int>>& visited,vector<vector<char>>& grid){
        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int nrow = row+dr[k];
                int ncol = col+dc[k];

                if(nrow >= 0 && ncol >=0 && nrow<R && ncol<C && grid[nrow][ncol] == 'O' && visited[nrow][ncol] == 0){
                    visited[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }

    void solve(vector<vector<char>>& grid) {

        int R = grid.size();
        int C = grid[0].size();
        
        vector<vector<int>> visited(R,vector<int>(C));
        queue<pair<int,int>> q;

        for(int i=0;i<R;i++){
            if(grid[i][0] == 'O'){
                visited[i][0] =1;
                q.push({i,0}); 
            }
            if(grid[i][C-1] == 'O'){
                visited[i][C-1] = 1;
                q.push({i,C-1});
            }
        }

        for(int i=0;i<C;i++){
            if(grid[0][i] == 'O'){
                visited[0][i] =1;
                q.push({0,i}); 
            }
            if(grid[R-1][i] == 'O'){
                visited[R-1][i] = 1;
                q.push({R-1,i});
            }
        }

        bfs(R,C,q,visited,grid);

        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(visited[i][j] == 0 && grid[i][j] == 'O'){
                    grid[i][j] = 'X';
                }
            }
        }
        }
};
