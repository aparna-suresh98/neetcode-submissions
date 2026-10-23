class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0,0,0};
        for(auto p : nums){
            count[p]++;
        }
        int index =0;
        for(int i=0;i<3;i++){
            while(count[i]--){
                nums[index] = i; 
                index++;
            }
        }
    }
};