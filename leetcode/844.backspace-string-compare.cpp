/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string tmp_s = "", tmp_t = "";
        for (char ch : s) {
            if (ch == '#' && tmp_s.size())
                tmp_s.pop_back();
            else if (ch >= 'a' && ch <= 'z')
                tmp_s.push_back(ch);
        }
        for (char ch : t) {
            if (ch == '#' && tmp_t.size())
                tmp_t.pop_back();
            else if (ch >= 'a' && ch <= 'z')
                tmp_t.push_back(ch);
        }
        return tmp_s == tmp_t;
    }
};
// @lc code=end

