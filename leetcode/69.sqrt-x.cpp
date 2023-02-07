/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) return 1;
        if (!x) return 0;
        unsigned int i;
        for (i = 2; i*i <= x; ++i);
        return i-1;
    }
};
// @lc code=end

