/*
 * @lc app=leetcode id=1742 lang=cpp
 *
 * [1742] Maximum Number of Balls in a Box
 */

// @lc code=start
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int box[46] = {0}, max = INT_MIN;
        for (int i = lowLimit; i <= highLimit; ++i) {
            int t = CalDigitSum(i);
            box[t]++;
            if (box[t] > max) max = box[t];
        }
        return max;
    }
    int CalDigitSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
};
// @lc code=end

