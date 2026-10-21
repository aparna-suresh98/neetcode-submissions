class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0]; //dance

        for(int i=1;i<strs.size();i++){
            string b = strs[i];
            int j=0;
            while(j < ans.size() && j < b.size() && ans[j] == b[j]){
                j++;
            }
            ans = ans.substr(0,j);

            if(ans == "") return "";
        }
        return ans;

    }
};