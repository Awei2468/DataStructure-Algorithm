/*
 * @lc app=leetcode id=709 lang=cpp
 *
 * [709] To Lower Case
 */

// @lc code=start
class Solution {
public:
    string toLowerCase(string s) {
        for (char &ch : s) {
            if (ch >= 'A' && ch <= 'Z')
                ch += ('a' - 'A'); 
        }
        return s;
    }
};
// @lc code=end

