class Solution {
public:
    void dfs(int i,vector<int>& visited,vector<vector<int>>& adj){
        visited[i] = 1;
        for(auto it : adj[i]){
            if(!visited[it]){
                dfs(it,visited,adj);
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
         for(auto& it : prerequisites){
            int a = it[0];
            int b = it[1];
            adj[a].push_back(b);
         }

         vector<vector<int>> reach(numCourses,vector<int> (numCourses,0));

         for(int i=0;i<numCourses;i++){
            vector<int> visited(numCourses,0);
            if(!visited[i])dfs(i,visited,adj);
            for(int j=0;j<numCourses;j++){
                if(j!=i && visited[j] == 1){
                    reach[i][j] = 1;
                }
            }
        }
        vector<bool> ans;
        
        for(auto& it : queries){
            int a = it[0];
            int b = it[1];
            if(reach[a][b] == 1){
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};