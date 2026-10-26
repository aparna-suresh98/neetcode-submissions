class Solution {
public:
    bool dfs(int i,vector<int>& vis,vector<int>& pathvis,vector<vector<int>>& adj,vector<int>& order){
        vis[i] = 1;
        pathvis[i] = 1;

        for(auto& it : adj[i]){
            if(!vis[it]){
                if(dfs(it,vis,pathvis,adj,order)) return true;
            } else {
                if(pathvis[it] == 1){
                    return true;
                }
            }
        }
        pathvis[i]=0;
        order.push_back(i);
        return false;

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto& it : prerequisites){
            int a = it[0];
            int b = it[1];

            adj[b].push_back(a);
        }

        vector<int> order;
        vector<int> vis(numCourses,0);
        vector<int> pathvis(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathvis,adj,order)) return {};
            }     
        }
        reverse(order.begin(),order.end());
        return order;
    }
};
