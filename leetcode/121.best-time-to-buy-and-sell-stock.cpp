/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0], max = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < min) {
                min = prices[i];
            }
            max = (prices[i] - min > max) ? prices[i] - min : max;
        }
        return max;
    }
};
// @lc code=end

