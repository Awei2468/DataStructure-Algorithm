/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;  //to count how many 5
        while (n > 0) {
            if (!(n % 3125))
                res += 5;
            else if (!(n % 625))
                res += 4;
            else if (!(n % 125))
                res += 3;
            else if (!(n % 25))
                res += 2;
            else if (!(n % 5))
                res += 1;
            n = (!res) ? n-1 : n-5;
        }
        return res;
    }
};
// @lc code=end

