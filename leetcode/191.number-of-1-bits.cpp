/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        uint32_t tmp = 0x80000000;
        while (tmp > 0) {
            if (n & tmp) ++res;
            tmp >>= 1;
        }
        return res;
    }
};
// @lc code=end

