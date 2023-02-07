/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        if (!s.size()) return 0;
        int res = 0, n = s.size();
        bool empty = true;
        for (int i = 0; i < n; ++i) {
            if (!i && s[i] == ' ') {
                while (s[i] == ' ')
                    ++i;
                if (i >= n) break;
            }
            if (s[i] != ' ') empty = false;
            if (s[i] == ' ' && i + 1 < n && s[i + 1] != ' ') ++res;
        }
        return empty ? res : res + 1;
    }
};
// @lc code=end

