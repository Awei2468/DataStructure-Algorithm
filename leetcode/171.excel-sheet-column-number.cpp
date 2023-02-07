/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        int t = 1;
        for (int i = columnTitle.size()-1; i >= 0; --i) {
            res += (t * (columnTitle[i]- 'A' + 1));
            if (!i) break;
            t *= 26;
        }
        return res;
    }
};
// @lc code=end

