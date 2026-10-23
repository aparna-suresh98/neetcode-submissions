class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(auto& p : nums){
            mp[p]++;
        }
        for(auto& p : mp){
            if(p.second > n/2){
                return p.first;
            }
        }
        return -1;
    }
};