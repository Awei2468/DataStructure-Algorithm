/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long x = abs(dividend), y = abs(divisor), res = 0;
        int tag = ((dividend > 0)^(divisor > 0)) ? -1 : 1;
        if (y == 1) return (tag == -1) ? -x : x;
        while (x >= y) {
            long t1 = y, t2 = 1;
            while (x >= (t1 << 1)) {
                t1 <<= 1;
                t2 <<= 1;
            }
            res += t2;
            x -= t1;
        }
        return (tag == -1) ? -res : res;
    }
};
// @lc code=end

