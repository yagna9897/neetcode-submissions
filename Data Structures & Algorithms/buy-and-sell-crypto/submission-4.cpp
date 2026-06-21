class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();

        int sell = prices[0];
        int profit = 0;
        for (int i = 1; i < length; i++) {
            int buy = prices[i];
            sell = min(sell, prices[i]);
            profit = max(profit, buy - sell);
        }
        return profit;
    }
};
