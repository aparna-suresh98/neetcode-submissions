class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maximum = INT_MIN;
        int minimum = INT_MAX;
        int total=0;
        int curmax =0;
        int curmin = 0;

        for(int i=0;i<n;i++){
            total+=nums[i];

            curmax+=nums[i];
            maximum = max(maximum,curmax);
            if(curmax < 0){
                curmax =0;
            }

            curmin+=nums[i];
            minimum = min(minimum,curmin);
            if(curmin > 0){
                curmin = 0;
            }

        }
        if(maximum < 0){
            return maximum;
        }
        return max(maximum,total - minimum);

    }
};