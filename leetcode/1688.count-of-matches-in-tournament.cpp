/*
 * @lc app=leetcode id=1688 lang=cpp
 *
 * [1688] Count of Matches in Tournament
 */

// @lc code=start
class Solution {
public:
    int numberOfMatches(int n) {
        int cnt = 0;
        while (n > 1) {
            cnt += (n >> 1);
            if (n & 1)
                n = (n >> 1) + 1;
            else
                n >>= 1;
        }
        return cnt;
    }
};
// @lc code=end

