/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for (char ch : s) res ^= ch;
        for (char ch : t) res ^= ch;
        return res;
    }
};
// @lc code=end

