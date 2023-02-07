/*
 * @lc app=leetcode id=1009 lang=cpp
 *
 * [1009] Complement of Base 10 Integer
 */

// @lc code=start
class Solution {
public:
    int bitwiseComplement(int n) {
        if (!n) return 1;
        int tmp = 0x7fffffff;
        int origin = n, cnt = 0;
        while (origin > 0) {
            ++cnt;
            origin >>= 1;
        }
        return n^(tmp >> (31-cnt));
    }
};
// @lc code=end

