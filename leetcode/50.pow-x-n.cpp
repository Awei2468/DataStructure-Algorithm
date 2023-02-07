/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        for (int i = n; i != 0; i /= 2) {
            if (i & 1) ans *= x;
            x *= x;
        }
        return  n > 0 ? ans : 1/ans;
    }
};
// @lc code=end

