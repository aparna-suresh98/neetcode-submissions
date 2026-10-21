class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int best=INT_MAX;
        int left=0;
        int sum=0;       
        
        for(int right=0; right<nums.size();right++){
            
            sum += nums[right];
            while(sum >= target){
                best = min(best,right-left+1);
                sum -= nums[left];
                left++;
            }
        }
        return (best == INT_MAX)? 0:best;
    }
};