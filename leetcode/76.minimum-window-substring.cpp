/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int map[128] = {0};
        int StartIndex = 0, EndIndex = 0, j = 0, head = 0, len = __INT_MAX__;
        for (auto c:t) map[c]++;
        while (EndIndex < s.length()) {
            char c = s[EndIndex++];
            if (map[c]-- > 0) j++;
            while (j == t.length()) {               
                if (EndIndex - StartIndex < len) {
                    head = StartIndex;
                    len = EndIndex - StartIndex;
                }
                char r = s[StartIndex++];
                if (map[r]++ == 0) j--;
            }
        }
        return len == __INT_MAX__ ? "" : s.substr(head, len);
    }
};
// @lc code=end

