class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minValue = prices[0];
        int maxprofit = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            minValue = min(prices[i], minValue);
            maxprofit = max(maxprofit, prices[i] - minValue);
        }
        return maxprofit;
    }
};
