class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }

        int minValue = prices[0];
        int profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            minValue = min(prices[i], minValue);
            profit = max(prices[i] - minValue, profit);
        }

        return profit;
    }
};
