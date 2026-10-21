class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();

        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};
        int perimeter = 0;

        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(grid[i][j] == 1){
                    
                    for(int k =0;k<4;k++){
                        int nrow = i+dr[k];
                        int ncol = j+dc[k];
                        bool outside = (nrow < 0 || nrow >= R || ncol < 0 || ncol >= C);
                        if(outside || grid[nrow][ncol] == 0){
                            perimeter++;
                        }
                    }
                }
            }
        }
        return perimeter;
    }
};