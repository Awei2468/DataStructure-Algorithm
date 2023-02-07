/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        int tmp = 0x7fffffff;
        int origin = num, cnt = 0;
        while (origin > 0) {
            ++cnt;
            origin >>= 1;
        }
        return num^(tmp >> (31-cnt));
    }
};
// @lc code=end

