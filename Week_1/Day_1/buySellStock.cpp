// Best time to Buy and Sell Stock

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuy = prices[0];
        int profit = 0;
        int maxProfit = 0;
        for (int i = 0;i < prices.size();i++) {
            bestBuy = min(bestBuy,prices[i]);
            profit = prices[i] - bestBuy;
            maxProfit = max(maxProfit,profit);
        }
        return maxProfit;
    }
};