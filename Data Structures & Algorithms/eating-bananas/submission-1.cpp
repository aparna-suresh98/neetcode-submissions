class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = high;
        while(low <= high){
            int mid = (low+high)/2;
            long long hours = 0;
            for(auto p : piles){
                hours+= p/mid;
                if(p % mid != 0) hours++;
            }
            if(hours <= h){
                ans = mid;
                high = mid -1;
            } else {
                low = mid +1;
            }
        }
        return ans;
    }
};
