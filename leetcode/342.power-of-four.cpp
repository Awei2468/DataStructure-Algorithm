/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int n) {
        /*
        int tmp = 0x7fffffff, cnt = 0, tmp2;
        if (n > 0 && !(n & (n-1))) {
            tmp2 = (n-1) & tmp;
            while (tmp2) {
                ++cnt;
                tmp2 >>= 1;
            }
            if (!(cnt % 2))
                return true;
            else
                return false;
        }
        else
            return false;
        */
        while (n && !(n % 4))
            n >>= 2;
        return n == 1;
    }
};
// @lc code=end

