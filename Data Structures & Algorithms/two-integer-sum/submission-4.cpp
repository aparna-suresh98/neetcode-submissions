class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int right=0;right<nums.size();right++){
            int left =1;
            while(left < nums.size()){
                if(nums[right]+nums[left] == target && right!=left){
                    return {right,left};
                }
                left++;
            }
        }
    }
};
