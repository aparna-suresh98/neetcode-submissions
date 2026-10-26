class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = high;

        while(low <= high){
            int mid = (low+high)/2;
            int daysCovered =1;
            int current  =0;

            for(auto w : weights){
                if(current + w > mid){
                    daysCovered++;
                    current =0;
                }
                current += w;
            }
            if(daysCovered <= days){
                ans = mid;
                high = mid -1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};