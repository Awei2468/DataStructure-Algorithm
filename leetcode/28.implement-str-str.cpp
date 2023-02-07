/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int x = haystack.length();
        int y = needle.length();
        if (!y) return 0;
        int i = 0, j = 0;
        while (i < x && j < y) {
            if (haystack[i] == needle[j]) {
                ++i;
                ++j;
            }
            else {
                i = i - j + 1;
                j = 0;
            }
        }
        if (j == y) return i-j;
        return -1;
    }
};
// @lc code=end

