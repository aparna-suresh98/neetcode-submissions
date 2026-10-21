class Solution {
public:

    void bfs(int R,int C,queue<pair<int,int>>& q,vector<vector<int>>& heights,vector<vector<int>>& ocean){
        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int nrow = row + dr[k];
                int ncol = col + dc[k];

                if(nrow>=0 && ncol>=0 && nrow<R && ncol<C && heights[nrow][ncol] >= heights[row][col] && ocean[nrow][ncol] == 0){
                    ocean[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }

            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int R = heights.size();
        int C = heights[0].size();

        vector<vector<int>> pacific(R,vector<int> (C,0));
        vector<vector<int>> atlantic(R,vector<int> (C,0));
        queue<pair<int,int>> pq,aq;

        for(int i=0;i<R;i++){
            pacific[i][0] = 1;
            pq.push({i,0});

            atlantic[i][C-1] = 1;
            aq.push({i,C-1});
        }

        for(int i=0;i<C;i++){
            pacific[0][i] = 1;
            pq.push({0,i});

            atlantic[R-1][i] = 1;
            aq.push({R-1,i});
        }

        bfs(R,C,pq,heights,pacific);
        bfs(R,C,aq,heights,atlantic);

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
