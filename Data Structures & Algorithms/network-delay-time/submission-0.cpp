class Solution {
public:
    int network_delay(vector<vector<pair<int,int>>>& adj,int k,int n){
        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        dist[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto& it : adj[node]){
                int adjnode = it.first;
                int w = it.second;

                if(w+distance < dist[adjnode]){
                    dist[adjnode] = w+distance;
                    pq.push({w+distance,adjnode});
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v,w});
        }

        int time = network_delay(adj,k,n);
        return time;
        }
};
