/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        string res = "", tmp;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                tmp += s[i];
            }
            else {
                reverse(tmp.begin(), tmp.end());
                res += (tmp + " ");
                tmp = "";
            }
        }
        reverse(tmp.begin(), tmp.end());
        res += tmp;
        return res;
    }
};
// @lc code=end

