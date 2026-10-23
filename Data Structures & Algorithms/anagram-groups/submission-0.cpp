class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for(auto& it : strs){
            string s = it;
            sort(s.begin(),s.end());
            groups[s].push_back(it);
        }
        vector<vector<string>> result;
        for(auto& p : groups){
            result.push_back(p.second);
        }
        return result;
        
    }
};
