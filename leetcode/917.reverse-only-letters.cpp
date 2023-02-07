/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 */

// @lc code=start
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.size()-1;
        while (i < j) {
            if (CheckAlpha(s[i]) && CheckAlpha(s[j])) {
                swap(s[i], s[j]);
                ++i;
                --j;
            }
            else if (CheckAlpha(s[i]) && !CheckAlpha(s[j]))
                --j;
            else if (!CheckAlpha(s[i]) && CheckAlpha(s[j]))
                ++i;
            else {
                ++i;
                --j;
            }
        }
        return s;
    }
    bool CheckAlpha(char c) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            return true;
        else
            return false;
    }
};
// @lc code=end

