class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n+1,0),out(n+1,0);
        for(auto it : trust){
            int a = it[0];
            int b = it[1];
            out[a]++;
            in[b]++;
        }
        for(int i=1;i<=n;i++){
            if(out[i] == 0 && in[i] == n-1){
                return i;
            }
        }
        return -1;
    }
};