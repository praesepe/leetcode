int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;
    
    int answer=0, outcome=0;
    int minValue = prices[0];
    
    for (int i=0; i<pricesSize; i++) {
        outcome = prices[i] - minValue;
        answer = (answer > outcome) ? answer : outcome;
        minValue = (minValue < prices[i]) ? minValue : prices[i];
    }
    
    return answer;
}
