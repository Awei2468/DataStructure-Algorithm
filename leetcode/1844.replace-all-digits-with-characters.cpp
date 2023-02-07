/*
 * @lc app=leetcode id=1844 lang=cpp
 *
 * [1844] Replace All Digits with Characters
 */

// @lc code=start
class Solution {
public:
    string replaceDigits(string s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i]-'0' >= 0 && s[i]-'0' <= 9) {
                s[i] = s[i-1] + (s[i]-'0');
            }
        }
        return s;
    }
};
// @lc code=end

