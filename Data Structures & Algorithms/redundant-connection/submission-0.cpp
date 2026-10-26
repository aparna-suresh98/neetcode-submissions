class Solution {
public:
    bool dfs(int a,int b ,vector<int>& visited,vector<vector<int>>& adj){
        if(a == b) return true;
        visited[a] = 1;
        for(auto& it : adj[a]){
            if(!visited[it]){
                if(dfs(it,b,visited,adj)) return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1);

        for(auto& it : edges){
            int a = it[0];
            int b = it[1];
            vector<int> visited(n+1,0);

            if(dfs(a,b,visited,adj)) return it;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        return {};

    }
};
