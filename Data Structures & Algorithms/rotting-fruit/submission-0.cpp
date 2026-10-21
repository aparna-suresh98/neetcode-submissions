class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int R = grid.size();
       int C = grid[0].size();

       vector<vector<int>> visited(R,vector<int>(C,0));
       queue<pair<pair<int,int>,int>> q;
       for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(grid[i][j] == 2){
                q.push({{i,j},0});
                visited[i][j] =2;
        }
       }
       }

       int tm =0;
       int dr[] = {1,-1,0,0};
       int dc[] = {0,0,1,-1};
       while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        tm = max(tm,t);
        q.pop();

        for(int k=0;k<4;k++){
            int nrow = row + dr[k];
            int ncol = col + dc[k];
            if(nrow >= 0 && ncol >= 0 && nrow < R && ncol <C && grid[nrow][ncol] != 0 && visited[nrow][ncol] != 2){
                q.push({{nrow,ncol},tm+1});
                visited[nrow][ncol] = 2;
            }
        }
       }

       for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(visited[i][j] != 2 && grid[i][j] == 1){
                return -1;
            }
        }
       }
       return tm;
    }
};
