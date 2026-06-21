class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        int result = 0;
        for(int i = 0; i < length; i++)
        {
            int iVal = prices[i];
            for(int j = i + 1; j < length; j++)
            {
                int jVal = prices[j];
                result = max(result, jVal - iVal);
            }
        }
        return result;
    }
};
