/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        /*
        if (num < 10) return num;
        int res = 0;
        while (num > 0) {
            res += num % 10;
            num /= 10;
        }
        return (res % 9 == 0) ? 9 : res % 9;
        */
        return (num == 0) ? 0 : ((num % 9 == 0) ? 9 : num % 9);
    }
};
// @lc code=end

