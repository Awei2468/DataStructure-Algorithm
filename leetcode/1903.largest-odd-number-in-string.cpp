/*
 * @lc app=leetcode id=1903 lang=cpp
 *
 * [1903] Largest Odd Number in String
 */

// @lc code=start
class Solution {
public:
    string largestOddNumber(string num) {
        string res = "";
        int idx = -1;
        for (int i = num.size()-1; i >= 0; --i) {
            if ((num[i]-'0') & 1) {
                idx = i;
                break;
            }
        }
        if (idx == -1) return res;
        for (int i = 0; i <= idx; ++i) {
            res += num[i];
        }
        return res;
    }
};
// @lc code=end

