class Solution {
public:
    int bfs(int C,int R,vector<vector<int>>& grid,queue<pair<int,pair<int,int>>>& q){
        int ans =0;
        while(!q.empty()){
            int time = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            int dr[] = {1,-1,0,0};
            int dc[] = {0,0,1,-1};

            for(int k=0;k<4;k++){
                int nrow = row+dr[k];
                int ncol = col+dc[k];

                if(nrow>=0 && ncol>=0 && nrow < R && ncol <C && grid[nrow][ncol] == 1){
                    grid[nrow][ncol] = 2;
                    q.push({time+1,{nrow,ncol}});
                    ans = time +1;
                }
            }

        }
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return ans;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        queue<pair<int,pair<int,int>>> q;

        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(grid[i][j] == 2){
                    q.push({0,{i,j}});
                }
            }
        }
    int mintime = bfs(C,R,grid,q);
    return mintime;
    }
};
