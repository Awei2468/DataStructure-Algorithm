/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 */

// @lc code=start
class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, now = 1, pre = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i-1])
                ++now;
            else {
                pre = now;
                now = 1;
            }
            if (pre >= now)
                ++ans;
        }
        return ans;
    }
};
// @lc code=end

