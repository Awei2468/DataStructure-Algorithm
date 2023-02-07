/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int j = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != ' ') {
                if (i != 0 && s[i-1] == ' ') j = 1;
                else j++;
            }
        }
        return j;
    }
};
// @lc code=end

