class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maximum = INT_MIN;
        int minimum = INT_MAX;
        int currmax = 0,currmin =0;
        int total = 0;

        for(int i=0;i<n;i++){
            total+=nums[i];

            currmax+=nums[i];
            maximum = max(maximum,currmax);

            if(currmax < 0){
                currmax = 0;
            }
            currmin+=nums[i];
            minimum = min(minimum,currmin);
            if(currmin > 0){
                currmin =0;
            }
        }
        if(maximum < 0) return maximum;
        return max(maximum,total-minimum);
    }
};