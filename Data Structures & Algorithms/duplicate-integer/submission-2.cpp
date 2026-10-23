class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(auto it:nums){
            seen.insert(it);
        }
        if(seen.size() != nums.size()) return true;
        else return false;
    }
};