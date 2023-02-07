/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(long x) {
        long long result = 0, origin = x;
        if (x < 0) x = -x;
        while (x) {
            result *= 10;
            result += (x % 10);
            if (result > __INT32_MAX__) return 0;
            x /= 10;
        }
        return (origin >= 0) ? (int)result : ((-result < ~__INT32_MAX__) ? 0 : (int)-result); 
    }
};
// @lc code=end

