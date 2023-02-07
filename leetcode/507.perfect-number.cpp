/*
 * @lc app=leetcode id=507 lang=cpp
 *
 * [507] Perfect Number
 */

// @lc code=start
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num & 1) return false;
        int sum = 0;
        for (int i = 1; i <= (num >> 1); ++i) {
            if (!(num % i))
                sum += i;
        }
        return sum == num;
    }
};
// @lc code=end

