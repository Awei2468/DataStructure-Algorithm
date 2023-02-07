/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        x ^= y;
        while (x > 0) {
            if (x & 1) ++res;
            x >>= 1;
        }
        return res;   
    }
};
// @lc code=end

