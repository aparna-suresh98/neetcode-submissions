class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        set<int> noduplicate(nums.begin(),nums.end());
        if(noduplicate.size() != n){
            return true;
        }
        return false;
    }
};