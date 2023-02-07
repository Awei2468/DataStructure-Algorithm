/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
private:
    int f[31];
public:
    Solution() {
        f[0] = 0; f[1] = 1;
        for (int i = 2; i < 31; ++i)
            f[i] = f[i-1] + f[i-2];
    }
    int fib(int n) {
        return f[n];
    }
};
// @lc code=end

