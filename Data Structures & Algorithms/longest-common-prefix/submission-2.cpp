class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = strs[0];
        for(int i=0;i<result.size();i++){
            for(int j=1;j<strs.size();j++){
                if(strs[j][i] != result[i]){
                    return result.substr(0,i);
                }
            }
        }
        return result;
    }
};