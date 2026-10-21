class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int n = nums.size();
        // for(int i=0; i<n; i++){
        //     if(count(nums.begin(),nums.end(),nums[i]) > n/2)
        //     return nums[i];
        // }
        // return -1;
        unordered_map<int,int> freq;
        int n = nums.size();

        // for(auto&x : nums){
        //     if(++freq[x] > n/2) return x;
        // }
        for(auto x : nums){
            freq[x]++;
            if(freq[x] > n/2){
                return x;
            }
        }
        return -1;
    }
};