class Solution {
public:
    void bfs(int i,vector<int>& visited,vector<vector<int>>& adj){
        queue<int> q;
        visited[i] = 1;
        q.push(i);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int v : adj[node]){
                if(!visited[v]){
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visited(n,0);
        int comp = 0;
        for(int i =0;i<n;i++){
            if(!visited[i]){
                comp++;
                bfs(i,visited,adj);
            }
        }
        return comp;
    }
};

