class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length == 0)
            return 0;
        
        int min = prices[0];
        int profit = 0;
        
        for(int i = 0 ; i < prices.length; i++){
            // to find buing date
            if(prices[i] < min) {
                min = prices[i];
                continue;
            }
            
            // to find selling date
            int spread = prices[i] - min;
            if(spread > profit)
                profit = spread;            
        }
        
        return profit;
    }
}
