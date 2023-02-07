/*
 * @lc app=leetcode id=397 lang=cpp
 *
 * [397] Integer Replacement
 */

// @lc code=start
class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if (!(n % 2)) return 1 + integerReplacement(n/2);
        else {
            long tmp = n;
            return 2 + min(integerReplacement((tmp - 1)/2), integerReplacement((tmp + 1)/2));
        }
    }
};
// @lc code=end

