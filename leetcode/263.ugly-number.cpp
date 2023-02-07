/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 */

// @lc code=start
class Solution {
public:
    bool isUgly(int n) {
        if (n < 1) return false;
        return (Calculate(n) == 1) ? true : false;
    }
    int Calculate(int x) {
        while (!(x % 2) || !(x % 3) || !(x % 5)) {
            if (!(x % 2))
                x /= 2;
            if (!(x % 3))
                x /= 3;
            if (!(x % 5))
                x /= 5;
        }
        return x;
    }
};
// @lc code=end

