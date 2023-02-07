/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        if (!b) return a;
        int sum = a ^ b;
        int carry = (a & b & INT_MAX) << 1;
        return getSum(sum, carry);
    }
};
// @lc code=end

