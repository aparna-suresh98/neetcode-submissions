class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();

        vector<vector<int>> distance(R,vector<int>(C,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        distance[0][0] = grid[0][0];
        pq.push({grid[0][0],{0,0}});

        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,-1,1};

        while(!pq.empty()){
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row == R-1 && col == C-1) return time;
            for(int k=0;k<4;k++){
                int nrow = row+dr[k];
                int ncol = col+dc[k];

                if(nrow >= 0 && ncol >= 0 && nrow < R && ncol < C){
                    int newtime = max(time,grid[nrow][ncol]);
                    if(newtime < distance[nrow][ncol]){
                        distance[nrow][ncol] = newtime;
                        pq.push({newtime,{nrow,ncol}});
                    }
                }
            }

        }
        return -1;
        

    }
};
