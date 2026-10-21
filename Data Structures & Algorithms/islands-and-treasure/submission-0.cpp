class Solution {
public:

    void bfs(int R,int C,vector<vector<int>>& grid,queue<pair<int,int>>& q){

    const int INF = 2147483647;
    int dr[] = {1,-1,0,0};
    int dc[] = {0,0,1,-1};
    
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int k=0;k<4;k++){
            int nrow = row + dr[k];
            int ncol = col + dc[k];

            if(nrow >= 0 && ncol >=0 && nrow <R && ncol <C && grid[nrow][ncol] == INF){
                grid[nrow][ncol] = grid[row][col]+1;
                q.push({nrow,ncol});    
            }
        }

    }
}
    void islandsAndTreasure(vector<vector<int>>& grid) {
    int R = grid.size();
    int C = grid[0].size();
     queue<pair<int,int>> q;

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(grid[i][j] == 0){
                q.push({i,j});
            }
        }
    }
    bfs(R,C,grid,q);
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    }
};
