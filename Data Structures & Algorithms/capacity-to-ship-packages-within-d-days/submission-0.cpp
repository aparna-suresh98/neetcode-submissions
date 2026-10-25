class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end()); //lowest value possible for the capacity
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = high;
        while(low <= high){
            int mid = (low+high)/2;
            int daysNeeded = 1; //days needed for the capacity
            int current =0;

            for(auto w : weights){
                if(current + w > mid){
                    daysNeeded++;
                    current =0;
                }
                current += w;
            }

            if(daysNeeded <= days){
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }

        }
        return ans;
    }
};