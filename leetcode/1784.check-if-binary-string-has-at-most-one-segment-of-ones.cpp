/*
 * @lc app=leetcode id=1784 lang=cpp
 *
 * [1784] Check if Binary String Has at Most One Segment of Ones
 */

// @lc code=start
class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size(), seg = 0;
        for (int i = 0, j; i < n; ++i) {
            if (s[i] == '1') {
                ++seg;
                if (seg > 1) return false;
                j = i + 1;
                while (j < n && s[j] == '1')
                    ++j;
                i = j - 1;
            }
        }
        return true;
    }
};
// @lc code=end

