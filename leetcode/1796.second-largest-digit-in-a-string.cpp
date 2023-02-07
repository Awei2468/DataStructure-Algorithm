/*
 * @lc app=leetcode id=1796 lang=cpp
 *
 * [1796] Second Largest Digit in a String
 */

// @lc code=start
class Solution {
public:
    int secondHighest(string s) {
        int res = -1, cnt = 0;
        int group[10] = {0};
        for (char c : s) {
            if (c >= '0' && c <= '9')
                group[c-'0']++;
        }
        for (int i = 9; i >= 0; --i) {
            if (group[i])
                ++cnt;
            if (cnt == 2) {
                res = i;
                break;
            }
        }
        return res;
    }
};
// @lc code=end

