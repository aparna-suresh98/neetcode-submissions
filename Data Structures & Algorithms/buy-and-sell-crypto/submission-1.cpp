class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best = 0;
        int minPrice = prices[0];
        for(int i = 1; i< prices.size(); i++){
            int profit = prices[i] - minPrice;
            best = max(best,profit);
            minPrice = min(minPrice,prices[i]);
        }
        return best;
    }
};
