class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int second = 0;
        for(int i = m;i<nums1.size();i++){
            nums1[i] = nums2[second];
            if(second<nums2.size()) second++; 
        }
        sort(nums1.begin(),nums1.end());
    }
};