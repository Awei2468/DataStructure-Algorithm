/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int stairs[3];  //reduce spaces
    int climbStairs(int n) {
        stairs[0] = 1; stairs[1] = 1;
        if (n == 1) return 1;
        for (int i = 2; i <= n; ++i) {
            stairs[2] = stairs[0] + stairs[1];
            stairs[0] = stairs[1];
            stairs[1] = stairs[2];
        }           
        return stairs[2];
    }
};
// @lc code=end

