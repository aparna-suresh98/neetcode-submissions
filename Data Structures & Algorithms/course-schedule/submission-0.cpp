class Solution {
public:
    bool dfs(int i,vector<int>& visited,vector<int>& pathvis,vector<vector<int>>& adj){
        visited[i] = 1;
        pathvis[i] = 1;

        for(auto& it : adj[i]){
            if(!visited[it]){
                if(dfs(it,visited,pathvis,adj)) return true;
            } else if (pathvis[it] == 1){
                return true;
            }
        }
        pathvis[i] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto p : prerequisites){
            int a = p[0];
            int b = p[1];
            adj[b].push_back(a);   //b comes before a ,ie 1 comes before 0 , 1->0
        }

        vector<int> visited(numCourses,0);
        vector<int> pathvis(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,visited,pathvis,adj)) return false;  //if cycle then cannot finish
            }
        }
        return true; //if cycle not there then can finish

    }
};
