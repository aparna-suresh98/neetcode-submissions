class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        int index = 0;
        for(auto p : s){
            nums[index] = p;
            index++;
        }
        
        return s.size();
    }
};