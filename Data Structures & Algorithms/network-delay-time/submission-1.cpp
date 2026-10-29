class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i =0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v,w});
        }

        vector<int> distance(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        distance[k] = 0;
        pq.push({0,k});
        int delaymax = 0;

        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto& p : adj[node]){
                int adjnode = p.first;
                int w = p.second;

                if(dist + w < distance[adjnode]){
                    distance[adjnode] = dist+w;
                    pq.push({dist+w,adjnode});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(distance[i] == INT_MAX) return -1;
            delaymax = max(delaymax,distance[i]);
        }
        return delaymax;

    }
};
