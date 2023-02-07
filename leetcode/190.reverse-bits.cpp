/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        stack<int> S;
        uint32_t res = 0;
        uint32_t tmp = 0x80000000, tmp2, count = 31;
        while (tmp > 0) {
            tmp2 = n & tmp;
            tmp2 >>= (count--);
            S.push(tmp2);
            tmp >>= 1;
        }
        tmp = 0x80000000;
        while (!S.empty()) {
            res += (S.top() * tmp);
            S.pop();
            tmp >>= 1;
        }
        return res;
    }
};
// @lc code=end

