//122. Best Time to Buy and Sell Stock II




class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*you can just sell when increase and buy when decrease cause even if the stock increases continously
        the net profit will still be same as subtracting the two end points for an increasing stock*/
        int netProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            // Only add profit when the price has increased compared to the previous day
            if (prices[i] > prices[i - 1]) {
                netProfit += prices[i] - prices[i - 1];
            }
        }
        return netProfit;
    }
};
