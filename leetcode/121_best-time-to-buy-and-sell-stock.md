#[121_best-time-to-buy-and-sell-stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

**simplified problem statement:**
given an array of prices of stock, choosing the i<sup>th</sup> day for buying stock and a different day in future to sell that stock, find the maximum profit you can generate

```
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
```

```cpp
class Solution {
    int maxProfit(vector<int>& prices) {
        int n=prices.size(), diff;
        vector<int> dpTable(n, 0);
        int minPrice=prices[0];
        
        for(int i=1; i<n; i++) {
            minPrice=min(prices[i], minPrice);
            diff=prices[i]-minPrice;
            dpTable[i]=max(minPrice, diff);
        }
    return dpTable[n-1];
}
```