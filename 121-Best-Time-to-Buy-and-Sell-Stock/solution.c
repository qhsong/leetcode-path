int maxProfit(int* prices, int pricesSize) {
    int minPrices=prices[0];
    if(pricesSize <= 1) return 0;
    int res = prices[1] - prices[0];
    int i;
    for(i=2;i<pricesSize;i++) {
        minPrices = prices[i-1] > minPrices? minPrices:prices[i-1];
        res = (prices[i] - minPrices)>res?(prices[i] - minPrices):res;
    }
    if(res<0) return 0;
    return res;
}