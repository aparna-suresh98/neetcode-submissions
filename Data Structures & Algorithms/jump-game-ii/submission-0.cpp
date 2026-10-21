class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jump =0,farthest = 0,curEnd = 0;

        for(int i=0;i<n-1;i++){
            farthest = max(farthest,i+nums[i]);
            if(curEnd == i){
                jump++;
                curEnd = farthest;
            }
        }
        return jump;
    }
};
