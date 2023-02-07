/*
 * @lc app=leetcode id=1281 lang=cpp
 *
 * [1281] Subtract the Product and Sum of Digits of an Integer
 */

// @lc code=start
class Solution {
public:
    int subtractProductAndSum(int n) {
        int p = 1, s = 0;
        while (n > 0) {
            p *= n % 10;
            s += n % 10;
            n /= 10;
        }
        return p - s;
    }
};
// @lc code=end

