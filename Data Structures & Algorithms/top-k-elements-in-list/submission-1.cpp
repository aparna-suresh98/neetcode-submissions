class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> result;

        for(auto it : nums){
            mp[it]++;
        }
        vector<pair<int,int>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](const pair<int,int> a,const pair<int,int> b){
            return a.second > b.second;
        });

        for(int i=0;i<k;i++){
            result.push_back(v[i].first);
        }
        return result;
    }
};
