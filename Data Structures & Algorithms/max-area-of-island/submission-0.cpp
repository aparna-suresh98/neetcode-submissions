class Solution {
public:
    int bfs(int i,int j,vector<vector<int>>& visited,vector<vector<int>>& grid){
        visited[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i,j});

        int n=grid.size();
        int m=grid[0].size();


        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        int count = 1;

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int k =0 ; k<4 ; k++){
            int drow = row + dr[k];
            int dcol = col + dc[k];

            if(drow >=0 && drow<n && dcol >=0 && dcol<m && grid[drow][dcol] == 1 && visited[drow][dcol] == 0){
                visited[drow][dcol] = 1;
                q.push({drow,dcol});
                count++;
            }
            }
        }

        return count;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int R= grid.size();
        int C= grid[0].size();
        vector<vector<int>> visited(R,vector<int>(C,0));
        int maxArea = 0;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                   int area = bfs(i,j,visited,grid);
                   maxArea = max(area,maxArea);
                }            
            }
        }
        return maxArea;

    }
};
