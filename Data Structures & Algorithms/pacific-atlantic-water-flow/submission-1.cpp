class Solution {
public:
        void dfs(int R,int C,vector<vector<int>>& heights,vector<vector<int>>& visited){
            int row = heights.size();
            int coloumn = heights[0].size();
            if(R<0 || C<0 || R>=row || C>=coloumn){
                return;
            }
            if(visited[R][C] == 1) return;
            visited[R][C] = 1;

            // Down
        if (R + 1 < row &&
            heights[R + 1][C] >= heights[R][C]) {
            dfs(R + 1, C, heights, visited);
        }

        // Up
        if (R - 1 >= 0 &&
            heights[R - 1][C] >= heights[R][C]) {
            dfs(R - 1, C, heights, visited);
        }

        // Right
        if (C + 1 < coloumn &&
            heights[R][C + 1] >= heights[R][C]) {
            dfs(R, C + 1, heights, visited);
        }

        // Left
        if (C - 1 >= 0 &&
            heights[R][C - 1] >= heights[R][C]) {
            dfs(R, C - 1, heights, visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int R = heights.size();
        int C = heights[0].size();

        vector<vector<int>> pacific(R,vector<int>(C,0));
        vector<vector<int>> atlantic(R,vector<int>(C,0));

        for(int i=0;i<R;i++){
            dfs(i,0,heights,pacific);
            dfs(i,C-1,heights,atlantic);
        }

        for(int i=0;i<C;i++){
            dfs(0,i,heights,pacific);
            dfs(R-1,i,heights,atlantic);
        }
        vector<vector<int>> ans;

        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};
