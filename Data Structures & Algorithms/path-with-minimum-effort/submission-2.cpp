class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int R = heights.size();
        int C = heights[0].size();

        vector<vector<int>> distance(R,vector<int> (C,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        distance[0][0] = 0;
        pq.push({0,{0,0}});

        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};

        while(!pq.empty()){
            int effort = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            for(int k=0;k<4;k++){
                int nrow = row+dr[k];
                int ncol = col+dc[k];

                if(nrow>=0 && ncol>=0 && nrow <R && ncol<C){
                    int neweffort = max(effort,abs(heights[nrow][ncol] - heights[row][col]));
                    if(neweffort < distance[nrow][ncol]){
                        distance[nrow][ncol] = neweffort;
                        pq.push({neweffort,{nrow,ncol}});
                    }
                }
            }
        }
        
        return distance[R-1][C-1];
    }
};